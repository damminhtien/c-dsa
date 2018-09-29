// TextServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "winsock2.h"

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9000);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);
	
	printf("Dang cho ket noi...\n");
	SOCKET client = accept(listener, NULL, NULL);


	printf("Ket noi thanh cong...\n");
	char *msg = "Hello client";
	send(client, msg, strlen(msg), 0);

	char buf[256];
	int ret;

	while (1)
	{
		ret = recv(client, buf, sizeof(buf), 0);
		if (ret <= 0)
			break;
		buf[ret] = 0;
		printf("%s\n", buf);
	}

	closesocket(client);

	closesocket(listener);
	WSACleanup();

	return 0;
}

