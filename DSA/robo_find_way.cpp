#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

int **map;
int n;

typedef struct {
	int x;
	int y;
}absolute;

absolute robot;

void createEmptyMap(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			map[i][j] = 0;
		}
	}
}

void print(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 0) cout << "  .";
			if(map[i][j] == 1) cout << "  R";
			if(map[i][j] == 2) cout << "  B";
		}
		cout << endl;
		cout << endl;
	}
}

void process(char c){
	if(c == '1'){
		if(robot.x-1 >= 0 && map[robot.x-1][robot.y] != 2){
			cout << c;
			map[robot.x][robot.y] = 0;
			robot.x = robot.x - 1;
		}
	}
	if(c == '2'){
		if(map[robot.x][robot.y+1] != 2 && robot.y +1 < n){
			map[robot.x][robot.y] = 0;
			robot.y = robot.y + 1;
		}
	}
	if(c == '3'){
		if(map[robot.x+1][robot.y] != 2 && robot.x+1 < n){
			map[robot.x][robot.y] = 0;
			robot.x = robot.x + 1;
		}
	}
	if(c == '4'){
		if(robot.y-1 >= 0 && map[robot.x][robot.y-1] != 2){
			map[robot.x][robot.y] = 0;
			robot.y = robot.y - 1;
		}
	} 
	map[robot.x][robot.y] = 1;
}

int main(){
	robot.x = 0;
	robot.y = 0;
	cout << "Input map size: "; cin >> n;
	map = new int*[n];
	for(int i=0; i<n; i++)
		map[i] = new int[n];
	createEmptyMap();
	while(1){
		int x = 0;
		int y = 0;
		cout << "Input absolute of barrier: " << endl;
		cout << "x = "; fflush(stdin); cin >> x;
		cout << "y = "; fflush(stdin); cin >> y;
		if(x > -1 && y > -1 && x < n && y < n) map[x][y] = 2;
		cout << "Have another barrier? <y/n> ";
		char c; fflush(stdin); cin >> c;
		if(c == 'n') break;
	}
	map[robot.x][robot.y] = 1;
	
	system("cls");
	cout << "Map: " <<endl;
	print();
	while(1){
		string way;
		cout << "\n1.Up 2.Right 3.Down 4.Left \nWay:"; fflush(stdin); getline(cin,way);
		for(int i=0; i<way.length(); i++){
			process(way[i]);
			system("cls");
			string sub = way.substr(i+1,way.length());
			cout << endl << sub << endl;
			print();
			Sleep(1000);
		}		
	}
	
	return 0;
}
