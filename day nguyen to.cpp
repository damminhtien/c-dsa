#include<iostream>
#include<math.h>
using namespace std;

int start, end;

bool isPrime(int n){
	if(n <= 1) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0) return false;
	}
	return true;
}

main(){
	cin >> start >> end;
	for(int i = start; i <= end; i++){
		if(isPrime(i)) cout << " " << i;
	}
}
