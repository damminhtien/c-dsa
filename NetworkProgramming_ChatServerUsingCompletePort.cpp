// ChatServerUsingOverlappedCompletePort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "winsock2.h"

// Data structure to get client's information
typedef struct _PER_HANDLE_DATA
{
	SOCKET client; // save socket handle
	SOCKADDR_IN clientAddr; // save socket adress
} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

// Data structure to get data from IO 
typedef struct _PER_IO_DATA
{
	OVERLAPPED overlapped;
	WSABUF data;
	char buf[1024];
} PER_IO_DATA, *LPPER_IO_DATA;

DWORD WINAPI WorkerThread(LPVOID);

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	// Create completion port obj
	HANDLE completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

	// Count processors
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);
	for (int i = 0; i < systemInfo.dwNumberOfProcessors; i++)
		CreateThread(0, 0, WorkerThread, completionPort, 0, 0);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9000);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	LPPER_HANDLE_DATA perHandleData;
	LPPER_IO_DATA perIoData;

	while (1)
	{
		SOCKADDR_IN clientAddr;
		int clientAddrLen = sizeof(clientAddr);

		SOCKET client = accept(listener, (SOCKADDR *)&clientAddr, &clientAddrLen);

		perHandleData = (LPPER_HANDLE_DATA)malloc(sizeof(PER_HANDLE_DATA));
		perHandleData->client = client;
		memcpy(&perHandleData->clientAddr, &clientAddr, clientAddrLen);

		// Mount socket client with completion port object
		CreateIoCompletionPort((HANDLE)client, completionPort, (DWORD)perHandleData, 0);

		perIoData = (LPPER_IO_DATA)malloc(sizeof(PER_IO_DATA));
		memset(&perIoData->overlapped, 0, sizeof(perIoData->overlapped));
		perIoData->data.buf = perIoData->buf;
		perIoData->data.len = sizeof(perIoData->buf);

		DWORD bytes = 0;
		DWORD flags = 0;

		// Send the first IO request
		WSARecv(client, &(perIoData->data), 1, &bytes, &flags, &(perIoData->overlapped), 0);
	}

	return 0;
}


DWORD WINAPI WorkerThread(LPVOID lpParam)
{
	HANDLE completionPort = (HANDLE)lpParam;
	LPPER_HANDLE_DATA perHandleData;
	LPPER_IO_DATA perIoData;
	DWORD bytes = 0;
	DWORD flags = 0;

	while (1)
	{
		// Wait IO's result
		GetQueuedCompletionStatus(completionPort, &bytes, (LPDWORD)&perHandleData, (LPOVERLAPPED *)&perIoData, INFINITE);
		if (bytes == 0)
		{
			closesocket(perHandleData->client);
			free(perHandleData);
			free(perIoData);
			continue;
		}

		// Process received data
		perIoData->buf[bytes] = 0;
		printf(perIoData->buf);


		// Send the next IO request
		flags = 0;
		memset(&(perIoData->overlapped), 0, sizeof(perIoData->overlapped));
		WSARecv(perHandleData->client, &(perIoData->data), 1, &bytes, &flags, &(perIoData->overlapped), 0);
	}

	return 0;
}

