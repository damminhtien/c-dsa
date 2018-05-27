//Name: Dam Minh Tien
//SDT: 01636612120
//Tks for your watching

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int M[4][4];
char ch[2];
int control;
int X1=0;
int Y1=1;
int X2=1;
int Y2=2;

void Run();
void Change();
void Print();
void Process(int);
void MakeColor();

void Change(){
	if(ch[0]=='w') control=1;
	if(ch[0]=='a') control=2;
	if(ch[0]=='s') control=3;
	if(ch[0]=='d') control=4;
	if(ch[0]!='w'&&ch[0]!='s'&&ch[0]!='a'&&ch[0]!='d'){
		printf("\nNo, pls press W,A,S,D to control!!!\nCareful: Turn off Capslock!!!");
		Run();
	} 
}

void Print(){
	system("cls");
	for(int i=0;i<4;i++){
		printf("\n");
		for(int j=0;j<4;j++){
	 	if(M[i][j]==0) printf(" * ");
	 	if(M[i][j]==1) printf(" P ");
	 	if(M[i][j]==2) printf(" B ");
	 	if(M[i][j]==3) printf(" D ");
		} 	
	}	 	
}

void Process(int control){
	if(control == 1){ 
		X1--;
		if(X1==X2&&Y1==Y2){
			if(X2==0){
				X1++;
				X2++;
			}
			X2--;
		} 
	}
	if(control == 2){
		Y1--;
		if(X1==X2&&Y1==Y2){
			if(Y2==0){
				Y1++;
				Y2++;
			}
			Y2--;
		}
	}
	if(control == 3){
		X1++;
		if(X1==X2&&Y1==Y2){
			if(X2==3){
				X1--;
				X2--;
			}
			X2++;
		}
	}
	if(control == 4){
		Y1++;
		if(X1==X2&&Y1==Y2){
			if(Y2==3){
				Y1--;
				Y2--;
			}
			Y2++;
		}
	}
}

int C(){
	if(X1<0||X1>3||Y1<0||X1>3) return -2;
	else{
		if((X2==0&&Y2==0)||(X2==3&&Y2==0)||(X2==0&&Y2==3)) return -1;
		else{
			if(X2==3&&Y2==3) return 0;
			else return 1;
		}
	}
}

void MakeColor(){
	system("color a1");
	Beep(523,100);
	Sleep(100);
	system("color b2");
	Beep(587,100);
	Sleep(100);
	system("color c3");
	Beep(523,100);
	Sleep(100);
	system("color d4");
	Beep(587,100);
	Sleep(100);
	system("color e5");
	Beep(523,100);
	Sleep(100);
	system("color f6");
	Beep(587,100);
	Sleep(100);
	system("color a0");
	Beep(523,100);
	Sleep(100);
	system("color 30");
	Beep(587,100);
	Sleep(100);
	system("color a0");
	Beep(523,100);
	Sleep(100);
	system("color b0");
	Beep(587,100);
	Sleep(100);
	system("color d0");
	Beep(523,100);
	Sleep(100);
	system("color df");
	Beep(587,100);
	Sleep(100);
}

void Run(){
	int Game=1;
	while(Game==1){
		int k=0;
		printf("\n\nHere, Your Move: ");
		gets(ch);
		Change();
		M[X1][Y1]=0;
		Process(control);
		Game=C();
		if(Game==-2){
			if(X1<0) X1++;
			if(X1>3) X1--;
			if(Y1<0) Y1++;
			if(Y1>3) Y1--;
			printf("\nNo, Get out of matrix,pls,EOF ");
			printf("\nRemove: \n");
			k=1;
			Run();
			}
		if(Game==-1){
			printf("\nNo, game end here! \n");
			M[X1][Y1]=1;
			M[X2][Y2]=2;
			Print();
			break;
			}
		if(Game==0){
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tYeah, YOU WON !!!");
			Sleep(500);
			MakeColor();
			break;
			}
		M[X1][Y1]=1;
		M[X2][Y2]=2;
		if(k==0) Print();
		}
}

int main(){
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	 	M[i][j]=0;
	M[X1][Y1]=1;
	M[X2][Y2]=2;
	M[3][3]=3;
	printf("Hello,Welcome To My Game: \n\tBoX PrObLeM\n");
	Sleep(1500);
	printf("You push the Box to Destination to Win");
	Sleep(1500);
	printf("\nPress W,A,S,D to control! \n");
	Sleep(1500);
	printf("Letfun!!!\n");
	Sleep(1500);
	printf("Good Luck! :)\nStart !!!!!!!");
	Sleep(2000);
	Print();
	int choose=1;
	while(choose == 1){
		fflush(stdin);
		Run();
		Sleep(2000);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDo U want to Replay ???\nPress 1 to say Yes or Press 0 to say No  ");
		scanf("%d",&choose);
		if(choose == 1){
			for(int i=0;i<4;i++)
	 		for(int j=0;j<4;j++)
	 			M[i][j]=0;
	 	X1=0;Y1=1;
	 	X2=1;Y2=2;
		M[0][1]=1;
		M[1][2]=2;
		Print();
		}
	}
	return 0;
}
