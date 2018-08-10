#include<iostream>
using namespace std;
 
typedef struct{
    int s,f;
}T;

void quickSort(T a[], int left,int right){
	int i,j;
	T x,y;
	i=left; j=right;
	x= a[(left+right)/2];
	do{
		while(x.s>a[i].s && i<right) i++;
		while(a[j].s>x.s && j>left) j--;
		if(i<=j){
			y=a[i];a[i]=a[j];a[j]=y;
			i++;j--;
		}
	}while (i<=j);
	if (left<j) quickSort(a,left,j);
	if (i<right) quickSort(a,i,right);
}

int main(){
    int n;
    cout << "Nhap so may: ";
    cin >> n;
    T x;
    cout << "Nhap thoi gian bat dau lam viec & ket thuc: ";
    cin >> x.s >> x.f;
    T a[20];
    for(int i=1; i<=n; i++){
    	cout << "Nhap may " << i << " : ";
    	cin >> a[i].s >> a[i].f;
    	cout << endl;
	}
    quickSort(a,1,n); 
    cout << "Da nhap: " << endl;
    for(int i = 1; i <= n; i++){
		cout << "May " << i << " : ";	
		cout << a[i].s << " " << a[i].f << endl;		
	}
	int max_f = 1;
	for(int i = 2; i <= n; i++){
		if(a[max_f].f < a[i].f && a[i].s <= x.s) max_f = i;
	}
	cout << "May chon lam moc: " << max_f;
	T kq[20];
	kq[1].s = a[max_f].s;
	kq[1].f = a[max_f].f;
	int dem_may = 1;
	int j = max_f+1;
	while(kq[dem_may].f < x.f && j <= n){
		kq[dem_may+1].f = kq[dem_may].f;
		for(int i = j; i <= n; i++){
			if(a[i].f > kq[dem_may+1].f && a[i].s <= kq[dem_may].f){
				kq[dem_may+1].f = a[i].f;
				kq[dem_may+1].s = a[i].s;
				j=i;
			}
		}
		dem_may++;j++;
	}
	cout << "\nKet qua: ";
	if(kq[dem_may].f < x.f) cout << "Ko co ket qua";
	else for(int i=1;i<=dem_may;i++){
			cout << "[" << kq[i].s << " " << kq[i].f << "]  ";
		}
}
