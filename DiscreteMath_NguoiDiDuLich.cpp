#include<iostream>
using namespace std;

int arr[10][10] = {};

int x[10] = {}, xOpt[10] = {};

int fk = 0, fOpt = 1000, n = 0, m =0, cmin = 1000;

void init(){
	freopen("nddl.txt","r",stdin);
	// doc n
	cin >> n;
	// doc ma tran
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if(arr[i][j] <= cmin && arr[i][j] > 0) cmin = arr[i][j];
		}
	}
	cout << n << endl;
	cout << cmin << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	} 
}

void ghinhan(){
	cout << "\nKQ: ";
	for(int i = 0; i < n; i++){
		cout << x[i] << " -> ";
	}
	cout << "1";
}

bool laUCV(int i, int k){
	for(int j = 1; j <= k; j++){
		if(x[j] == i) return false;
	}
	return true;
}

void Branch(int k){
	for(int i = 2; i <= n; i++){
		if(laUCV(i,k)){
			x[k] = i;
			fk += arr[x[k-1]][i];
			if(k == n-1){
				if(fk + arr[k][1]< fOpt){
					fOpt = fk + arr[k][1];
					for(int j = 1; j < n; j++)
						xOpt[j] = x[j];	
				}
				ghinhan();
				cout << "\n" << fOpt;
			}
			else if(fk + cmin*(n-k) < fOpt) Branch(k+1);
			fk -= arr[x[k-1]][i];	
		}
	}
}

main(){
	init();
	x[0] = 1;
	Branch(1);
	cout << "\nfOpt: " << fOpt;
	cout << endl;
	for(int j = 1; j < n; j++) cout <<  xOpt[j] << " ";
}
