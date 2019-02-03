#include <bits/stdc++.h>

using namespace std;

double mathFunction(double x){
	return 2*(x*x)-(12*x)+7;
}

long long ternarySearch(int a, int b){
	double l =  (double)a, r = (double)b;
	for(int x=0; x<200; x++){
		double l1 = l+(r-l)/3;
		double l2 = r-(r-l)/3;
		if(mathFunction(l1) < mathFunction(l2)){
			r = l2;
		}else{
			l = l1;
		}
	}
	return (long long)(round(mathFunction(l)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,a,b;
	cin>>t;
	while(t-- && cin>>a>>b){
		cout<<ternarySearch(a,b)<<endl;
	}
	return 0;
}