#include<iostream>

using namespace std;

int a[20];
int n,m;

void ghinhan(){
	cout << endl;
	for(int i = 1; i <= m; i++)
		cout << " " << a[i];
}

bool laUCV(int i, int k){
	for(int j = 1; j < k; j++){
		if(a[j] == i) return false;
	}
	return true;
}

void Try(int k){
	for(int i = 1; i <= n; i++){
		if(laUCV(i,k)){
			a[k] = i;
			if(k == m) ghinhan();
			else Try(k+1);
		}		
	}
}

main(){
	cin >> n >> m;
	Try(1);
}
