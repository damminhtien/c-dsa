#include<iostream>

using namespace std;

int a[20];
int n,m;

void ghinhan(){
	cout << endl;
	for(int i = 1; i <= m; i++)
		cout << " " << a[i];
}

void Try(int k){
	for(int i = a[k-1]+1; i <= n - m + k; i++){
		a[k] = i;
		if(k == m) ghinhan();
		else Try(k+1);	
	}
}

main(){
	cin >> n >> m;
	Try(1);
}
