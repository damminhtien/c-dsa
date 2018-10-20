#include<iostream>
#include<math.h>

using namespace std;

int a[20] = {};
int n = 0;
int count = 0;

bool laUCV(int i, int k){
	for(int j = 1; j < k; j++){
		if(i == a[j] || fabs(i - a[j]) == k - j) return false;
	}
	return true;
}

void ghinhan(){
	cout << endl;
	for(int i = 1; i <= n; i++ ){
		cout << " " << a[i];
	}
	count++;
}

void Try(int k){
	for(int i = 1; i <= n; i ++){
		if(laUCV(i,k)){
			a[k] = i;
			if(k == n) ghinhan();
			else Try(k+1);
		}
	}
}

main(){
	cin >> n;
	Try(1);
	cout << endl << count;
}
