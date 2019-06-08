#include <bits/stdc++.h>

using namespace std;

int p, q, d;

void extendedEuclid(int a, int b){
	if(b == 0){
		p = 1, q = 0, d = a;
		return;
	}
	extendedEuclid(b, a%b);
	int x1 = q;
	int y1 = p - (a / b) * q;
	p = x1;
	q = y1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, x, k;
	cin>>t;
	while(t-- && cin>>x>>k){
		int a = floor(x/k), b = ceil((double)x/(double)k);
		extendedEuclid(a,b);
		int gcdDivision = x/d;
		p*=gcdDivision, q*=gcdDivision, d*=gcdDivision;
		cout<<p<<" "<<q<<"\n";;
	}
	return 0;
}
