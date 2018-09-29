// DataClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
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

	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9000);

	system("pause");

	int ret = connect(client, (SOCKADDR *)&addr, sizeof(addr));
	if (ret == SOCKET_ERROR)
	{
		ret = WSAGetLastError();
		printf("Error code: %d", ret);
		system("pause");

		return 1;
	}

	char buf[256];
	ret = recv(client, buf, sizeof(buf), 0);
	if (ret <= 0)
	{
		printf("Recv Error!");
		system("pause");
		return 1;
	}

	buf[ret] = 0;
	printf("%s", buf);
	int n;

	SINHVIEN sv;

	while (1)
	{
		printf("Nhap du lieu:");
		printf("MSSV: ");
		scanf("%d", &sv.mssv);
		while (getchar() != '\n');
		printf("Ho ten: ");
		gets_s(sv.hoten);
		printf("Diem Toan: ");
		scanf("%f", &sv.dToan);
		printf("Diem Ly: ");
		scanf("%f", &sv.dLy);
		printf("Diem Hoa: ");
		scanf("%f", &sv.dHoa);

		send(client, (char *)&sv, sizeof(sv), 0);
	}

	closesocket(client);
	WSACleanup();

	system("pause");

	return 0;
}


