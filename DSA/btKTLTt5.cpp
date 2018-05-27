#include<iostream>
#include<string.h>
#include<string>

using namespace std;

typedef struct {
  int masv;  
  char malop[12];
  char ho[30];
  char ten[30];
  float diemk1;
  float diemk2;
} sinhvien;

typedef struct sv{
	int masv;  
  	char malop[12];
  	char ho[30];
  	char ten[30];
  	float diemk1;
 	float diemk2;
	sv *svNext = NULL;
	sv *svPrev = NULL;
}sv;

void showFunction(){
	cout << "\nThere are 4 function:            " << endl;
	cout << "1 . Input student data:          "   << endl;
	cout << "2 . Show student list:           "   << endl;
	cout << "3 . Find student with name:      "   << endl;
	cout << "4 . Sort by avg mark:            "   << endl;
}

sv *inputData(sv *head){
	sv *newStd = new sv;
	cout << "Student Code        : "; fflush(stdin); cin >> newStd->masv; 
	cout << "First Name          : "; fflush(stdin); gets(newStd->ho);
	cout << "Last Name           : "; fflush(stdin); gets(newStd->ten);
	cout << "Class Code          : "; fflush(stdin); gets(newStd->malop);
	cout << "First semester mark : "; fflush(stdin); cin >> newStd->diemk1;
	cout << "Second semester mark: "; fflush(stdin); cin >> newStd->diemk2;
	if(head->svNext == NULL){
		head->svNext   = newStd;
		head->svPrev   = newStd;
		newStd->svNext = head;
		newStd->svPrev = head;
	}
	else{
		sv *temp = head;
		while(temp->svNext != head && strcmp(temp->svNext->ten,newStd->ten) < 0) temp = temp->svNext;
		newStd->svNext       = temp->svNext;
		newStd->svPrev       = temp;
		temp->svNext->svPrev = newStd;
		temp->svNext         = newStd;	
	}
	
	return head;
}

void showStdInfo(sv *std){
	cout << "Student Code        : " << std->masv   << endl;
	cout << "First Name          : " << std->ho     << endl; 
	cout << "Last Name           : " << std->ten  	 << endl;
	cout << "Class Code          : " << std->malop  << endl; 
	cout << "First semester mark : " << std->diemk1 << endl;
	cout << "Second semester mark: " << std->diemk2 << endl; 
}

void showList(sv *head){
	if(head->svNext == NULL) cout << "Not thing to show!!!" << endl;
	else{
		sv *std;
		std = head->svNext;
		int count = 1;
		while(std != head){
			cout << count << endl;
			showStdInfo(std);
			count++;
			std = std->svNext;
		}	
	}
		
}

sv *findStudent(sv *head, char *ten){
	if(head->svNext == NULL) return NULL;
	else{
		sv *fStd = head->svNext;
		while(fStd != head && strcmp(strlwr(ten),strlwr(fStd->ten)) != 0) fStd = fStd->svNext;
		if(fStd == head) return NULL;
		else return fStd;
	}
}

sv *cloneOf(sv *std){
	sv *cloneStd = new sv;
	cloneStd->masv = std->masv;
	strcpy(cloneStd->ho,std->ho);
	strcpy(cloneStd->ten,std->ten);
	strcpy(cloneStd->malop,std->malop);
	cloneStd->diemk1 = std->diemk1;
	cloneStd->diemk2 = std->diemk2;
	return cloneStd;
}

float avgMark(sv *std){
		return 0.5*(std->diemk1 + std->diemk2);
}

sv *sortList(sv *head){
	sv *newhead = new sv;
	if(head->svNext == NULL) return NULL;
	else if(head->svNext->svNext == head) newhead = head;
	else{
		sv *std = head->svNext;
		while(std != head){
			sv *newStd = new sv;
			newStd = cloneOf(std); 
			if(newhead->svNext == NULL){
				newhead->svNext   = newStd;
				newhead->svPrev   = newStd;
				newStd->svNext    = newhead;
				newStd->svPrev    = newhead;
			}	
			else{
				sv *tempStd = newhead;
				while(tempStd->svNext != newhead && avgMark(tempStd->svNext) < avgMark(newStd) ) 
					tempStd = tempStd->svNext;
				newStd->svNext          = tempStd->svNext;
				newStd->svPrev          = tempStd;
				tempStd->svNext->svPrev = newStd;
				tempStd->svNext         = newStd;	
			}
			std = std->svNext;
		}	
	}
	return newhead;
}

int main(int argc, char *argv[]){
	sv *head = new sv;
	cout << "Student Manage System\n_____________________________________";
	int flag = 1;
	while(flag){
		showFunction();
		fflush(stdin);
		int choose = -1;
		cout << "Your selection (1-4): "; cin >> choose;
		cout <<"_____________________________________\n";
		
		switch(choose){
			case 1: cout << "\nInput data:"<< endl;             
					head = inputData(head);   
					break;
			case 2: cout << "\nShow student list: "<< endl;     
			        showList(head);    
					break;
			case 3: cout << "\nFind student: " << endl;
					char ten[30];
					cout << "Input name of student: "; fflush(stdin); gets(ten);          
			        sv *fStd; 
					fStd = findStudent(head,ten);
					if(fStd == NULL) cout << "Student Not Found! " << endl;
					else{
						showStdInfo(fStd);	
					}
					break;
			case 4: cout << "\nSort by average mark: " << endl; 
			        sv *newhead;
					newhead = sortList(head);
					if(newhead == NULL) cout << "Not thing to sort !!!" << endl;
					else showList(newhead); 
					break;
			default: cout << "\nError, press one number in [1,4]" << endl;  
		}
		
		cout << "Do you want to continue? Press 1 to do again, 0 to end." << endl;
		fflush(stdin);
		cin >> flag;
	}
	return 0;
}















