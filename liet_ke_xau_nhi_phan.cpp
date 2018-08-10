#include<iostream>

using namespace std;

int a[20] = {};
int n = 0;

void ghinhan(){
	cout << endl;
	for(int i = 1; i <= n ;i++){
		cout << " " << a[i];
	}
}

void Try(int k){
	for(int i = 0; i <= 1; i++){
		a[k] = i;
		if(k == n) ghinhan();
		else Try(k+1);
	}
}

main(){
	cin >> n;
	Try(1);
}

