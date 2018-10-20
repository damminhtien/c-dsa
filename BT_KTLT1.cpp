// Sequence: 1,2,3,4,4,5,8,11,12,14,21,30,35,40,56,...

#include<iostream>
using namespace std;

// This function calculate element in position n with Recursive Algorithm.
int getElementRecursive(int n){
	if(n <= 4) return n;
	else return getElementRecursive(n-1) - getElementRecursive(n-2) + getElementRecursive(n-3) + getElementRecursive(n-4);
}

// This function calculate total element from 1 to n with Recursive Algorithm.
int totalRec(int n){
	if(n == 1) return 1;
	else return totalRec(n-1) + getElementRecursive(n);
}

// This function calculate element in position n without Recursive Algorithm.
int getElementNonRecursive(int n){
	if(n <= 4) return n;
	else{
		int element1 = 1;
		int element2 = 2;
		int element3 = 3;
		int element4 = 4;
		int elementi = 0;
		for(int i = 5; i <= n; i++){
			elementi = element1 + element2 - element3 + element4;
			element1 = element2;
			element2 = element3;
			element3 = element4;
			element4 = elementi;
		}
		return elementi;
	}
}

// This function calculate total element from 1 to n without Recursive Algorithm.
int totalNonRec(int n){
	if(n == 1) return 1;
	else if(n == 2) return 3;
	else if(n == 3) return 6;
	else if(n == 4) return 10;
	else{
		int total = 10;
		int element1 = 1;
		int element2 = 2;
		int element3 = 3;
		int element4 = 4;
		int elementi = 0;
		for(int i = 5; i <= n; i++){
			elementi = element1 + element2 - element3 + element4;
			total += elementi;
			element1 = element2;
			element2 = element3;
			element3 = element4;
			element4 = elementi;
		}
		return total;
	}
}

int main(int argc, char *argv[]){
	int n;
	do{
		cout << "Input n [ n>=1 ]:  ";
		cin >> n;
	}while(n<=0);
	cout << "_______________________\nOutput:\n" << endl;
	
	cout << "Recursion: " << endl;
	cout << "Sequence from 1 to " << n << " :     ";
	for(int i = 1; i <= n; i++){
		cout << getElementRecursive(i) << " ";
	}
	cout << "\nTotal element from 1 to " << n << ": " << totalRec(n) << endl;  
	
	cout << "\nNon-recursion: " << endl;	
	cout << "Sequence from 1 to " << n << " :     ";
	for(int i = 1; i <= n; i++){
		cout << getElementRecursive(i) << " ";
	}
	cout << "\nTotal element from 1 to " << n << ": " << totalNonRec(n) << endl;
	return 0;
}






