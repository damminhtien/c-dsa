// Client2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "winsock2.h"
#include "ws2tcpip.h"

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	
	/*addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("123.30.215.16");
	addr.sin_port = htons(80);*/

	addrinfo *res;
	int ret = getaddrinfo("genk.vn", "http", NULL, &res);
	if (ret == 0)
	{
		memcpy(&addr, res->ai_addr, res->ai_addrlen);
	}
	else
	{
		printf("Khong phan giai duoc ten mien");
		system("pause");
		return 1;
	}

	ret = connect(client, (SOCKADDR *)&addr, sizeof(addr));
	if (ret == SOCKET_ERROR)
	{
		ret = WSAGetLastError();
		printf("Error code: %d", ret);
		system("pause");

		return 1;
	}

	char *msg = "GET / HTTP/1.1\nHost: genk.vn\n\n";
	send(client, msg, strlen(msg), 0);

	char buf[256];

	while (1)
	{
		ret = recv(client, buf, sizeof(buf), 0);
		if (ret <= 0)
			break;
		if (ret < sizeof(buf))
			buf[ret] = 0;

		printf("%s", buf);
	}

	closesocket(client);
	WSACleanup();

	system("pause");

	return 0;
}

