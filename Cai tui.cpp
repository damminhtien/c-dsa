#include<iostream>
#define MAXITEM 20
using namespace std;

typedef struct{
	int c;
	int w;
}item;

item *i;
int x[MAXITEM] = {};
int xOpt[MAXITEM] = {};

int fk, fOpt, bk, b, n;

void Branch(int k){
	cout << "\nk: " << k;
	for(int j = 1; j >= 0; j--){
//		bk = bk - i[k].w;
//		cout << "\nbk: " << bk << endl;
//		if(bk >= 0){
//			x[k] = 1;
//			fk = fk + i[k].c;
//			if(k == n){
//				if(fk > fOpt){
//					fOpt = fk;
//					for(int l = 1; l <= n; l++)
//						xOpt[l] = x[l];
//				}
//			}
//			else if(fk + (float) bk*i[k+1].c/i[k+1].w > fOpt)
//				Branch(k+1);
//			fk += i[k].c;
//			x[k] = 0;
//		}
//		bk += i[k].w;
//		cout << "\nj: " << j;	
		x[k] = j;
		bk -= j*i[k].w;
		fk += j*i[k].c;
//		cout << "\nbk: " << bk;
//		cout << "\nfk: " << fk;
		if(k == n){
			if(fOpt < fk && bk >= 0) fOpt = fk;
		}
		else if(fk + (float) i[k+1].c*bk/i[k+1].w > fOpt) Branch(k+1);
		bk += j*i[k].w;
		fk -= j*i[k].c;
	}	
}

void init(){
//	freopen("ct.txt","r",stdin);
	cin >> n >> b;
	i = new item[n+1];
	for(int j = 1; j <= n; j++){
		cin >> i[j].w;
		cin >> i[j].c;
	}
//	for(int j = 1; j <= n; j++){
//		
//	}
	bk = b;
	fk = 0;
	fOpt = -1;
}

main(){
	init();
	for(int j = 1; j <= n; j++){
		cout << endl << i[j].c << " " << i[j].w;
	}
	Branch(1);
	cout << endl << "fOpt: " << fOpt;
}

