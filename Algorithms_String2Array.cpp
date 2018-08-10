#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

#define MAX_LINE_LEN 30

using namespace std;

string addStr(int *InputArr, int &index,int arrLen){
	string addStr;
	int tempIndex = index +2;
	int addNum = 2;
	while((InputArr[index] == InputArr[tempIndex] - addNum) && tempIndex < arrLen){
		tempIndex++;
		addNum++;
	}
	tempIndex--;
	if(tempIndex >= index+2 && tempIndex < arrLen){
		char numBegin[3];
		itoa (InputArr[index],numBegin,10);
		char numEnd[3];
		itoa (InputArr[tempIndex],numEnd,10);
		addStr += numBegin;
		addStr += "-";
		addStr += numEnd;
		addStr += ",";
		index = tempIndex;
	}
	else{
		char num[3];
		itoa (InputArr[index],num,10);
		addStr += num;
		addStr += ",";
	}
	return addStr;
}

void convertStringToArray(string InputStr,int *InputArr){
	
	int InputStrLen = InputStr.length();
	int strIndex = 0;
	int arrIndex = 0;
	string tempStr;
	while(strIndex < InputStrLen-1){
		if(InputStr[strIndex] != ','){
			tempStr += InputStr[strIndex];
		}
		else{
			InputArr[arrIndex] = atoi(tempStr.c_str());
			tempStr.clear();
			arrIndex++;
		}
		strIndex++;
	}
	InputArr[arrIndex] = atoi(tempStr.c_str());
}

void printArr(int *InputArr,int arrLen){
	cout << "Input Array:  ";
	for(int i=0; i<arrLen; i++){
		cout << InputArr[i] << " ";
	}
}

void convertArrayToString(string &OutputStr, int *InputArr, int arrLen){
	int arrIndex = 0;
	int strIndex = 0;
	int strLineLen = 0;
	 
	while(arrIndex < arrLen){
		string tempStr;
		tempStr += addStr(InputArr,arrIndex,arrLen);
		if(strLineLen + tempStr.length() <= MAX_LINE_LEN){
			OutputStr += tempStr;
			strLineLen += tempStr.length();
		}
		else{
			OutputStr += "\n";
			OutputStr += tempStr;
			strLineLen = 0;
			strLineLen += tempStr.length();
		}
		arrIndex++;
	}
	OutputStr =  OutputStr.substr(0,OutputStr.length()-1);
	OutputStr += ".";
}

int main(int argc, char *argv[]){
	
	string InputStr; 
	string OutputStr;
	int *InputArr;
	
	cout << "Enter the input string <end by a dot> :  "; 
	getline(cin,InputStr);
	cout << "____________________________________________________\n\n";
	cout << "Input String: " << InputStr << endl;
	
	int InputStrLen = InputStr.length();
	int InputArrLen = InputStrLen/4;
	
	InputArr = new int[InputArrLen];
	
	convertStringToArray(InputStr,InputArr);
	printArr(InputArr,InputStrLen/4);
	convertArrayToString(OutputStr,InputArr,InputArrLen);
	
	cout << "\nOutput String: " << endl << OutputStr << endl;
	delete []InputArr;
	return 0;
}
