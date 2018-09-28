#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "winsock2.h"
#include "ws2tcpip.h"

int main()
{
	// Khoi tao winsock
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) == SOCKET_ERROR)
	{
		int ret = WSAGetLastError();
		printf("Error code: %d!", ret);
		return 1;
	}
	
	// xac dinh dia chi ip va cong chay
	SOCKADDR_IN addr;
	// Ho dia chi ip
	addr.sin_family = AF_INET;
	// ip 127.168.0.1 dang so 4 byte network-byte-order
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// port 8000
	addr.sin_port = htons(8000);


	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	printf("Waiting for new client...\n");

	SOCKADDR_IN clientAddr;
	int clientAddrLen = sizeof(clientAddr);

	SOCKET client = accept(listener, (SOCKADDR *)&clientAddr, &clientAddrLen);
	printf("Client IP: %s\n", inet_ntoa(clientAddr.sin_addr));
	printf("Client socket value: %d\n", client);

	char msg[] = "Hello Client.";
	send(client, msg, strlen(msg), 0);

	while (1)
	{
		printf("Waiting for data...\n");
		char buf[256];
		int ret = recv(client, buf, sizeof(buf), 0);

		if (ret <= 0)
		{
			ret = WSAGetLastError();
			printf("Connection error. Error code: %d", ret);
			system("PAUSE");
			return 1;
		}

		buf[ret] = '\0';
		printf("Received: %s", buf);
	}

	system("PAUSE");
	WSACleanup();

	return 0;
}

