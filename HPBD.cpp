#include<stdio.h> 
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<string>

using namespace std;

void printLine(string line){
	cout << "              ";
	for(int i = 0; i < line.length(); i++){
		cout << line[i];
		Sleep(50);
	}
}

void hinh1(){
	string line;
	cout << endl;
	line = "................ ......................."; printLine(line); cout << endl; 
	line = "...............=?+?++++++=,............."; printLine(line); cout << endl;		
	line = "........ ..=?+??++++++==++++=..........."; printLine(line); cout << endl;
	line = "...... .,+????++++++++++++++++=........."; printLine(line); cout << endl;
	line = "......,?????++++++++++++++++++++:......."; printLine(line); cout << endl;
	line = ".....+?????+++++++++++++++++++++++......"; printLine(line); cout << endl;
	line = "....???????+++?+++++++++++++7++++++....."; printLine(line); cout << endl;
	line = "...++?????++8OO8++++++++++8OO8+++++=...."; printLine(line); cout << endl;
	line = "..=???????+?OOOOI++++++++?8OO8=+++++: .."; printLine(line); cout << endl;
	line = "..???????++?O888++++++++++?8OZ+++++++..."; printLine(line); cout << endl;
	line = ".,???????++++++++++++++++++++++++++++,.."; printLine(line); cout << endl;
	line = ".=???????++++++++++++++++++++++++++++~.."; printLine(line); cout << endl;
	line = ".+???????++++++++++++++++++++++++++++=.."; printLine(line); cout << endl;
	line = ".:???????++++++++++++++++++++++++++++=.."; printLine(line); cout << endl;
	line = "..???????++++++++++++++++++++++++++++:.."; printLine(line); cout << endl;
	line = "..?+?????+++++++++++++++++++D8+++++++..."; printLine(line); cout << endl;
	line = "...??????+++++++88D=+++++++O8++++++++..."; printLine(line); cout << endl;
	line = "...,??????++++++++88O8==ZO8?++++++++,..."; printLine(line); cout << endl;
	line = ".....?????+++++++++??IOZ+?+++++++++:...."; printLine(line); cout << endl;
	line = "......?????+++++++++++++++++++++++:....."; printLine(line); cout << endl;
	line = ".......,????++++++++++++++++++++=......."; printLine(line); cout << endl;
	line = "..........????++++++++++++++++~........."; printLine(line); cout << endl;
	line = ".............~???++++++++++,............"; printLine(line); cout << endl;
	line = "........................... ............"; printLine(line); cout << endl;
	line = "........................................"; printLine(line); cout << endl;	
}


int main(){
	hinh1();
	char str[100];
	cout << "\n                  Xin Moi Nhap Ten Cua Ban: ";
	gets(str);
	Sleep(500);
	cout << "                          Chao " << str << " !"<< endl;
	Sleep(1000);
	// ham thoi gian trong ctime
	time_t hientai = time(0);
   	char* dt = ctime(&hientai);
  	cout << "                 Bay gio la: " << dt << endl;
  	// mau me
  	Sleep(500);
  	cout << "......" << endl;
  	Sleep(500);
  	cout << "......" << endl;
	Sleep(500);
  	cout << "......" << endl;
	Sleep(500);
  	cout << "......" << endl;
  	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  	system("color 00");
	int i = 0;
	while(i < 120){
		printf("..HPBD TO YOU..>");
		Sleep(50);
		i++;
	}
	//
	system("color af");
	Sleep(100);
	system("color bf");
	Sleep(100);
	system("color cf");
	Sleep(100);
	system("color df");
	Sleep(100);
	system("color ef");
	Sleep(100);
	system("color f6");
	Sleep(100);
	system("color af");
	Sleep(100);
	system("color 3f");
	Sleep(100);
	system("color af");
	Sleep(100);
	system("color bf");
	Sleep(100);
	system("color df");
	Sleep(100);
	//
	Beep(523,400);//do //989 si
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nHAP");
	Beep(523,400);
	printf("PY");
	Beep(587,400);//re
	printf("	BIRTH");
	Beep(523,400);
	printf("DAY");
	Beep(698,400);//fa
	printf("	TO");
	Beep(659,400);//mi
	printf("	YOU");
	Sleep(500);
	//
	Beep(523,400);//do
	printf("\nSinh");
	Beep(523,400);
	printf("\n	Nhat");
	Beep(587,400);
	printf("\n		Vui");
	Beep(523,400);
	printf("\n			Ve");
	Beep(783,400);//sol
	Beep(698,400);
	printf(" !!!");
	Sleep(500);
	//
	Beep(523,400);
	printf("\n				Good");
	Beep(523,400);
	printf("	Day");
	Beep(523,400);
	Beep(880,400);//la
	Beep(698,400);
	Beep(659,400);
	Sleep(500);
	//
	Beep(587,400);
	Beep(880,400);
	Beep(880,400);
	Beep(880,400);
	Beep(659,400);
	Beep(659,400);
	Beep(698,400);
	Sleep(100);
	//
	for(int i=0;i<5;i++){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n    _......_,s$$.");
	Sleep(50);
	printf("\n  .$$$$$$$s$$ss$$$$,");
	Sleep(50);
	printf("\n  $$$sss$$$$s$$$$$$$");
	Sleep(50);
	printf("\n  $$ss$$$$$$$$$$$$$$");
	Sleep(50);
	printf("\n  '$$$s$$$$$$$$$$$$'");
	Sleep(50);
	printf("\n   '$$$$$$$$$$$$$$'");
	Sleep(50);
	printf("\n     $$$$$$$$$$$$'");
	Sleep(50);
	printf("\n     '$$$$$$$$$$'");
	Sleep(50);
	printf("\n      '$$$$$$$$'");
	Sleep(50);
	printf("\n       '$$$$$$'");
	Sleep(50);
	printf("\n        '$$$$'");
	Sleep(1000);	
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n    		   Best Things For You " <<str << endl;
	Sleep(1500);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	Sleep(1500);
	cout << "BEST REGARD, DMT" << endl;
}
