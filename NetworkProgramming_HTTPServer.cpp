#include <iostream>
#include <winsock2.h>
#include <windows.h>

using namespace std;

DWORD WINAPI ClientThread(LPVOID);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);
	
	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9000);
	
	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);
	
	while(1){
		SOCKET client = accept(listener, NULL, NULL);
		CreateThread(0, 0, ClientThread, &client, 0, 0);
	}
	

	return 0;
}

DWORD WINAPI ClientThread(LPVOID lpParam){
	SOCKET client = *(SOCKET *) lpParam;
	int ret;
	
	while(1){
		char buf[256];
		char cmd[16], loc[16], proto[16], tmp[256];
		ret = recv(client, buf, sizeof(buf), 0);
		if (ret >= 2){
			buf[ret] = 0;
			cout << "Command: " << buf;
			sscanf(buf, "%s %s %s %s", cmd, loc, proto, tmp);
			if(strcmp(cmd, "GET") == 0 && strcmp(loc,"/") == 0 && strcmp(proto, "HTTP/1.1") == 0){
				char html[2048];
				strcpy(html, "HTTP/1.1 200 OK\nContent-Type: text/html;charset=utf8\n\n<html>");
				WIN32_FIND_DATAA DATA;
				HANDLE h = FindFirstFileA("C:\\*.*",&DATA);
				do {
					if (DATA.dwFileAttributes &
					FILE_ATTRIBUTE_DIRECTORY){
						// Ðây là m?t thu m?c
						// In ra tên thu m?c
						cout << DATA.cFileName << endl;
						strcat(html, "<b>");
						strcat(html, DATA.cFileName);
						strcat(html, "</b><br>");
					} else {
						// Ðây là m?t file
						// In ra tên file và kích thu?c file
						cout << DATA.cFileName << endl;
						strcat(html, "<i>");
						strcat(html, DATA.cFileName);
						strcat(html, "</i><br>");
					}
				} while (FindNextFileA(h, &DATA));
				strcat(html, "</html>");
				send(client, html, strlen(html), 0);
			}
		}
		else break;
	}
}
