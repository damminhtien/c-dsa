#include <iostream>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string>

using namespace std;

void nonUI();
void jb();
void wwyamc();

void nonUI(){
	cout << "\t\t\tHello, you're welcome!!!"<< endl;
	cout << "\t          ************************************";
	Sleep(1800);
	
	cout << "\n\n\n\nComputer: " <<endl;
//	 tra ve date & time, bien now
	time_t now = time(0);
	char *dt = ctime(&now);
	cout <<"\t- It's: " << dt;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
//	in lenh neu hom nay la noel
//	 50 ma ASCII cua 2, trong C++ ko ho tro ss giua pointer & char kieu: c == "2" :(
	if(dt[8] == 50 && dt[9] == 52){
		cout << "\t- YEP :) , this night is NOEL" << endl;
//		if(dt[11] == )
	} 
	else cout << "\t- This night isn't NOEL, but hope you have fun"<< endl;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
	if(dt[11] == 48){
		if(dt[12] <= 50) cout << "\t- Good night, you should sleep early :)";
		if(dt[12] > 50 && dt[12] <=52) cout << "\t- Good morning !!!, have a best experience :) \n\t-  I don't know you wake up early or sleep late." << endl;
		if(dt[12] > 52 && dt[12] > 52) cout << "\t- Good morning !!!, hope you have a best experience :) \n\t-  I think you should have a breakfast :)" << endl;
	} 
	if(dt[11] == 49){
		if(dt[12] <= 51) cout << "\t- Do you have lunch ? >> " << endl;
		if(dt[12] > 51 && dt[12] <= 55) cout << "\t- Good afternoon!!!\n\t- Oh, people ussally say \"afternoon\" so why don't them say \"Good beforenoon\" or \"Good noon\"" << endl;
		if(dt[12] > 55 && dt[12] <= 57) cout << "\t- Good evening!!!\n\t- I think you should spend time to watch the NEWS on VTV3 :)\n\t-  Or not? :)" << endl;
	}
	if(dt[11] == 50){
		if(dt[12] <= 50) cout << "\t- Good evening!!!\n\t-  Did you have a good dinner?? :)" << endl;
		if(dt[12] > 50 && dt[12] <= 52) cout << "Good night!!!\n\t-  I think you should go to bed early :)" << endl;
	}
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
	cout << "\t- To greeting, I don't sure..." << endl << "\t  What your name ??? " << endl;
	cout << "User: " << endl << "\t- ";
	string name;
	getline (cin,name);
	cout << "Computer : " <<endl;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
	cout << "\t- Okay, hello " << name << " . It's a beautiful name :))" << endl;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
	cout << "\t- " << name << ", do you like music :))" << endl;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	
	cout << "\t- Press Y/N" << endl;
	cout << "User: " << endl;
	cout << "\t- ";
	string str;  
	getline(cin,str);
	int k;
	cout << "Computer: " << endl;
	
	Sleep(1000);
	cout << "\t ";
	for(int i=0;i<3;i++){
		cout << ". ";
		Sleep(500);
	}
	cout << endl;

	
	if(str[0] == 121 || str[0] == 89){
		cout << "\t- Of course, you like music :)" << endl;
		cout << "\t- So..." << endl;
		k=1;
	}
	else{
		cout << "\t- Oh, you don't like music :0" << endl;
		cout << "\t- But... try to ..." << endl;
		k=2;
	}
	cout << "\t- Choose one song to play :v" << endl << endl;
	
	
	int flag = 1;
	while(flag == 1){
		int control = 0;
		cout << "\t >    Menu" << endl;
		cout << "\t 1. Jingle bell." << endl;
		cout << "\t 2. We wish you a merry christmas." << endl;
		cout << "User:" << endl << "\t- " ;
		scanf("%d",&control);
		switch(control){
			case 1: jb(); break;
			case 2: wwyamc(); break; 
		}
		cout << "-\t Do you want to repeat? (press 1 to yes and 0 to say no) " << endl;
		cout << "User:" << endl << "\t- " ;
		scanf("%d",&flag);	
		cout << "Computer: " << endl;
	}
	
}
// do 532, re 587, mi 659, fa 698, sol 783,la 880, si 989
void jb(){
	Beep(783,400);
	Beep(783,400);
	Beep(659,400);
	Beep(587,400);
	Beep(532,400);
	Beep(783,400);
	
	Sleep(500);
	
	Beep(783,400);
	Beep(783,400);
	Beep(659,400);
	Beep(587,400);
	Beep(532,400);
	Beep(880,400);
	
	Sleep(500);
	
	Beep(880,400);
	Beep(880,400);
	Beep(698,400);
	Beep(659,400);
	Beep(587,400);
	Beep(989,400);
	
	Sleep(500);
	
	Beep(783,400);
	Beep(783,400);
	Beep(698,400);
	Beep(587,400);
	Beep(659,400);
	
	Sleep(700);
// do 532, re 587, mi 659, fa 698, sol 783,la 880, si 989

	Beep(783,400);
	Beep(783,400);
	Beep(659,400);
	Beep(587,400);
	Beep(532,400);
	Beep(783,400);

	Sleep(500);
	
	Beep(783,400);
	Beep(783,400);
	Beep(659,400);
	Beep(587,400);
	Beep(532,400);
	Beep(880,400);
	
	Sleep(500);
	
	Beep(880,400);
	Beep(880,400);
	Beep(698,400);
	Beep(659,400);
	Beep(587,400);
	Beep(783,400);

	Sleep(500);

	Beep(783,400);
	Beep(783,400);
	Beep(783,400);
	Beep(880,400);
	Beep(783,400);
	Beep(698,400);
	Beep(587,400);
	Beep(532,400);
	
	Sleep(500);
// do 532, re 587, mi 659, fa 698, sol 783,la 880, si 989

	Beep(659,400);
	Beep(659,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(659,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(783,400);
	Beep(532,400);
	Beep(587,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(698,400);
	Beep(698,400);
	Beep(698,400);
	
	Sleep(500);
	
	Beep(698,400);
	Beep(698,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(659,400);
	

	
	Beep(587,400);
	Beep(587,400);
	Beep(587,400);
	Beep(659,400);
	Beep(587,400);
	Beep(783,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(659,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(659,400);
	Beep(659,400);
	
	Sleep(500);

	Beep(659,400);
	Beep(783,400);
	Beep(532,400);
	Beep(587,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(698,400);
	Beep(698,400);
	Beep(698,400);
	
	Sleep(500);
	
	Beep(698,400);
	Beep(698,400);
	Beep(659,400);
	
	Sleep(500);
	
	Beep(659,400);
	Beep(659,400);
	
	
	Beep(783,400);
	Beep(783,400);
	Beep(698,400);
	Beep(587,400);
	Beep(532,400);
}

void wwyamc(){
}

main(){
	nonUI();
}
