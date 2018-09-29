// Client1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "winsock2.h"

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8000);

	int ret = connect(client, (SOCKADDR *)&addr, sizeof(addr));
	if (ret == SOCKET_ERROR)
	{
		ret = WSAGetLastError();
		printf("Error code: %d", ret);
		system("pause");

		return 1;
	}

	char *msg = "Hello server!";
	send(client, msg, strlen(msg), 0);

	char buf[256];

	while (1)
	{
		ret = recv(client, buf, sizeof(buf), 0);
		if (ret <= 0)
			break;

		buf[ret] = 0;
		printf("%s", buf);
	}
	
	closesocket(client);
	WSACleanup();

	system("pause");

    return 0;
}

