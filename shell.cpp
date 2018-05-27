#include<iostream>
#include<dirent.h>
#include<stdlib.h>
#include<string>
using namespace std;

void listCommand(){
	cout << "List of Command: " << endl;
	cout << "1. dir" << endl;
	cout << "2. createProcess" << endl;
	cout << "3. readBat" << endl;
}

int dir(){
	DIR *dir;
	struct dirent *ent;
	cout<<"List of file name: "<<endl;
	int n_file=0;
	if ((dir = opendir ("C:/Users/USER/")) != NULL) {
  	/* print all the files and directories within directory */
  	while ((ent = readdir (dir)) != NULL) {
  		n_file++;
		cout<<n_file; 
   		cout<<"\t"<<ent->d_name<<endl;
	}
  		closedir (dir);
  		cout<<"\t\t\t\tTotal: "<<n_file<<" file(s)"<<endl; 
	} else {
  	/* could not open directory */
  	perror ("");
  	return EXIT_FAILURE;
	}
}

void createProcess(){
	
}

void readBat(){
	
}

void controlCmd(string str){
	if(str == "dir") dir(); 
	else if(str == "createProcess") createProcess(); 
	else if(str == "reatBat") readBat(); 
	else cout << str << "is not recognized as an internal command, operable program or batch file." << endl; 
}

int main(int argc,char *argv[]){
	string cmd;
	cout << "\t\tWelcome to My_Basic_Shell !!!" << endl;
	cout << "\t\t\tCreated by DMT" << endl;
	cout << " _____________________________________________" << endl;
	listCommand();
	cout << "_________________" << endl;
	cout<<"Your Command :  "<<endl;
    getline(std::cin,cmd);
	fflush(stdin);
	cout << "_________________" << endl;
	controlCmd(cmd);
}









