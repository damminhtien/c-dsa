// WebServer.cpp : Defines the entry point for the console application.
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
	addr.sin_port = htons(8080);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	while (1)
	{
		SOCKET client = accept(listener, NULL, NULL);

		char buf[1024];
		int ret;

		// Nhan yeu cau tu trinh duyet
		ret = recv(client, buf, sizeof(buf), 0);
		buf[ret] = 0;
		printf("%s", buf);

		/*char cmd[16], path[1024];
		sscanf(buf, "%s %s", cmd, path);*/

		if (strncmp(buf + 4, "/xinchao", 8) == 0)
		{
			// Tra ket qua cho trinh duyet
			char *header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
			send(client, header, strlen(header), 0);

			char *content = "<html><body><h1>Xin chao</h1></body></html>";
			send(client, content, strlen(content), 0);
		}
		else if (strncmp(buf + 4, "/hello", 6) == 0)
		{ 
			// Tra ket qua cho trinh duyet
			char *header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
			send(client, header, strlen(header), 0);

			char *content = "<html><body><h1>Hello</h1></body></html>";
			send(client, content, strlen(content), 0);
		}
		else if (strncmp(buf + 4, "/image", 6) == 0 || strncmp(buf + 4, "/favicon.ico", 12) == 0)
		{
			// Tra ket qua cho trinh duyet
			char *header = "HTTP/1.1 200 OK\nContent-Type: image/jpg\n\n";
			send(client, header, strlen(header), 0);

			FILE *f = fopen("C:\\test_server\\city.jpg", "rb");
			while (1)
			{
				ret = fread(buf, 1, sizeof(buf), f);
				if (ret > 0)
					send(client, buf, ret, 0);
				else
					break;
			}

			fclose(f);
		}
		else
		{
			// Tra ket qua cho trinh duyet
			char *header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
			send(client, header, strlen(header), 0);

			char *content = "<html><body><h1>Yeu cau khong duoc ho tro</h1></body></html>";
			send(client, content, strlen(content), 0);
		}

		// Dong ket noi
		closesocket(client);
	}

	closesocket(listener);
	WSACleanup();

    return 0;
}

