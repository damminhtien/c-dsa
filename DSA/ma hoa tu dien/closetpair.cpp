#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define Task "closestpair"
#define maxn 200002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

pii a[maxn], strip[maxn];
double ans = 1e10;

double Distance(pii P1, pii P2){    
	double XX = P1.X - P2.X;    
	double YY = P1.Y - P2.Y;    
	return sqrt(XX*XX + YY*YY);
}

double bruteForce(pii P[], int n){    
	double kmin = FLT_MAX;    
	for (int i = 0; i < n; i++)        
		for (int j = i+1; j < n; j++)            
			kmin = min(kmin, Distance(P[i], P[j]));    
	return kmin;
}

bool compareY(pii p1, pii p2){    
	return (p1.Y < p2.Y || (p1.Y == p2.Y && p1.X < p2.X));
}

double stripClosest(pii strip[], int n, double d){    
	double kmin = d;    
	for (int i = 0; i < n; ++i)        
		for (int j = i+1; j < n && (strip[j].Y - strip[i].Y) <kmin; j++)        
			kmin = min(Distance(strip[i],strip[j]), kmin);    
	return kmin;
}

double Calc(pii P[], int n){    
	if (n <= 3){        
		sort (P, P+n, compareY);        
		return bruteForce(P, n);    
	}    
	int mid = n/2;    
	pii midPoint = P[mid];    
	double dl = Calc(P, mid);    
	double dr = Calc(P + mid, n-mid);
	double d = min(dl, dr);    
	int ccount = 0;    
	merge(P, P+mid, P+mid, P+n, strip,compareY);    
	for (int i = 0; i < n; i++){        
		P[i] = strip[i];        
	if (abs(strip[i].X - midPoint.X) < d)         
		strip[ccount++] = strip[i];    
	}    
	return min(d, stripClosest(strip, ccount, d));
}
	
double Closest(pii a[], int n){    
	sort(a, a+n);    
	return Calc(a,n);
}
	
int main(){
	ios_base::sync_with_stdio(0);    
	freopen(Task".inp", "r", stdin);    
	freopen(Task".out", "w", stdout);    
	int n;    cin >> n;    
	for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;    
	printf("%0.5f", Closest(a,n));    
	return 0;
}
