// DataServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "winsock2.h"

typedef struct {
	int mssv;
	char hoten[30];
	float dToan, dLy, dHoa;
} SINHVIEN;

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
	int ret, n;
	SINHVIEN sv;

	while (1)
	{
		ret = recv(client, buf, sizeof(buf), 0);
		if (ret <= 0)
			break;
		
		memcpy(&sv, buf, sizeof(sv));

		printf("Du lieu nhan duoc:\n");
		printf("MSSV: %d\n", sv.mssv);
		printf("Ho ten: %s\n", sv.hoten);
		printf("Diem Toan: %f\n", sv.dToan);
		printf("Diem Ly: %f\n", sv.dLy);
		printf("Diem Hoa: %f\n", sv.dHoa);
	}

	closesocket(client);

	closesocket(listener);
	WSACleanup();

	return 0;
}

