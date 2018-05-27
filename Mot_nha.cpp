#include<stdio.h>
#include<windows.h>
void beep(int hz){
	Beep(hz,300);
}
int main(){
	int do1=262;
	int re=294;
	int mi=330;
	int fa=350;
	int sol=392;
	int la=440;
	int si=494;
	int do2=523;
	int re2=588;
	int mi2=660;
	int fa2=700;
	int sol2=784;
	int la2=880;
	int si2=988;
	/*Khi hai ta v? m?t nhà, khép dôi mi chung m?t giu?ng
Mi2 Mi2 Mi2 Ðô2 Ðô2 Si, Rê2 Ðô2 Si Si Si La
Khi hai ta chung m?t du?ng, ta vui chung m?t n?i vui
Mi2 Mi2 Mi2 Ðô2 Ðô2 Si, Rê2 Rê2 Rê2 Rê2 Sol2 Mi2
Nu?c m?t roi m?t dòng, s?ng chung nhau m?t d?i
Mi2 Mi2 Ðô2 Sol La, Mi2 Rê2 Rê2 Ðô2 Ðô2*/
	beep(mi2);
	beep(mi2);
	beep(mi2);
	beep(do2);
	beep(do2);
	beep(si);
	beep(si);
	beep(re2);
	beep(do2);
	beep(si);
	beep(si);
	beep(si);
	beep(la);
	Sleep(500);
	//Ðôi khi mo cùng m?t gi?c, th?c gi?c chung m?t gi?
	//Ðô2 Ðô2 Si Sol La Ðô2, Mi2 Mi2 Rê2 Ðô2 Ðô2
	
}
