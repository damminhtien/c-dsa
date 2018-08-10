#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

char trangtri();
void nhacxms(string notes);

int main() {
	srand(time(0));

	system("COLOR F0");

	string ten;
	cout << "Chao ban! moi ban nhap ten 1 nguoi =))) : ";
	getline(cin, ten);

	int t;
	cout << "ban nam nay bao nhieu tuoi: ";
	cin >> t;

	system("COLOR 00");
	Sleep(700);
	system("COLOR A1");
	Sleep(700);
	system("COLOR C2");
	Sleep(700);
	system("COLOR 80");
	Sleep(700);
	system("COLOR 02");

	cout << endl << endl;

	system("cls");

	for (int f = 0; f < 12; f++) {
		system("cls");

		for (int j = 0; j < t + 16 - 18; j++) cout << " ";
		cout << "MERRY CHRISTMAS & HAPPY NEW YEAR 2016,";
		cout << endl;

		for (unsigned int j = 0; j < t + 16 - ten.length()/2; j++) cout << " ";
		cout << ten << endl << endl;


		for (int i = 0; i < t; i++) {
			cout << "\t\t";
			for (int j = 0; j < t - i; j++) cout << " ";
			for (int k = 0; k <= 2*i; k++) {
				if (k == 0 || k == 2*i) cout << "*";
				else cout << trangtri();
			}
			cout << endl;
		}

		for (int k = 0; k < 4; k++) {
			cout << "\t\t ";
			for (int j = 0; j < t-t%2-2; j++) cout << " ";
			for (int i = 0; i < 2*(t%2)+3; i++) cout << "*";
			cout << endl;
		}

		Sleep(500);
	}

	system("COLOR E0");
	Sleep(800);
	system("COLOR E3");
	Sleep(800);
	system("COLOR E8");
	nhacxms("E+");
	Sleep(800);
	system("COLOR E9");
	Sleep(800);
	system("COLOR E2");
	Sleep(800);
	system("COLOR EC");
	nhacxms("E+");
	Sleep(800);
	system("COLOR C6");
	Sleep(900);
	system("COLOR C9");
	Sleep(900);
	system("COLOR 02");
	Sleep(2000);
	cout << endl << endl << endl;

	cout << "\tSANTA CLAUS IS COMING TO HUST \\M/ \\M/" << endl << endl;
	system("COLOR 08");

	cout << "\tYou";
	nhacxms("G ");
	cout << " better watch out,";
	nhacxms("EFG G");
	cout << " you better not cry," << endl;
	nhacxms("   GAB B B");
	system("COLOR 02");
	
	//nhacxms("G EFG G   GAB B B"); //you better watch out you better not cry

	Sleep(500);
	cout << "\tBetter not pout"; 
	nhacxms("EF G G    ");
	cout <<" I'm telling you why," << endl;
	nhacxms("G AG F  F ");
	system("COLOR 05");
	
	//nhacxms("EF G G    G AG F  F "); // better not pout i'm telling u why

	Sleep(500);
	cout << "\tSanta Claus ";
	nhacxms("E  G  C  ");
	cout << "is coming";
	nhacxms("E  D  F   ");
	cout << " to town!!!!...." << endl;
	nhacxms("F-  C|");
	system("COLOR 02");
	
	//nhacxms("E  G  C  E  D  F   F-  C|"); //santa clause is coming to town

	cout << endl << endl;

	Sleep(2000);
	cout << "\tHe's";
	nhacxms("G ");
	cout << " making a list,";
	nhacxms("EFG G");
	cout << " he's checking it twice," << endl;
	nhacxms("   GAB B B");
	system("COLOR 02");

	Sleep(500);
	cout << "\tGonna find out"; 
	nhacxms("EF G G    ");
	cout <<" who's naughty or nice," << endl;
	nhacxms("G AG F  F ");
	system("COLOR 05");

	Sleep(500);
	cout << "\tSanta Claus ";
	nhacxms("E  G  C  ");
	cout << "is coming";
	nhacxms("E  D  F   ");
	cout << " to town!!!!...." << endl;
	nhacxms("F-  C|");
	system("COLOR 0C");

	Sleep(500);
	cout << "\tSanta Claus ";
	nhacxms("E  G  C  ");
	cout << "is coming";
	nhacxms("E  D  F   ");
	cout << " to town!!!!...." << endl;
	nhacxms("F-  C|");
	system("COLOR 02");

	Sleep(1000);
	cout << endl << endl << "\tHave a happy holiday!! :3.";
	cout << endl << "\tEnjoy endless music :)))))))).";
	cout << endl << "\tA Christmas gift from: #DMT.";

	while (true) {
		nhacxms("G EFG G   GAB B B");
		Sleep(500);
		nhacxms("EF G G    G AG F  F ");
		Sleep(500);
		nhacxms("E  G  C  E  D  F   F-  C|");
		Sleep(2000);
	}

	cin.get();
}

char trangtri() {
	int r = std::rand() % 10;

	if (r==1) return 'o';
	if (r==2) return '~';
	if (r==3) return '*';
	if (r==4) return '*';
	if (r==5) return '*';
	if (r==6) return 'o';
	if (r==7) return '~';
	if (r==8) return '+';
	if (r==9) return '*';
	if (r==0) return 'o';

	return 0;
}

void nhacxms(string notes) {
	char notenhac, notenhacp;
	int hz = 0;

	for (unsigned int i = 0; i < notes.length(); i++) {
		notenhacp = ' ';
		notenhac = ' ';

		notenhac = notes.at(i);
		if (i < notes.length() - 1) notenhacp = notes.at(i+1);

		if (notenhac == ' ') {
			Sleep(100);
			continue;
		}

		if (notenhac == 'C')  hz = 262;
		if (notenhac == 'D')  hz = 294;
		if (notenhac == 'E')  hz = 330;
		if (notenhac == 'F')  hz = 349;
		if (notenhac == 'G')  hz = 392;
		if (notenhac == 'A')  hz = 440;
		if (notenhac == 'B')  hz = 494;

		if (notenhacp == '-') {
			hz -= 100;
			i++;
		}
		if (notenhacp == '+') {
			hz += 100;
			i++;
		}

		if (notenhacp != '|') Beep(hz, 250);
		else {
			Beep(hz, 800);
			i++;
		}
	}
}
