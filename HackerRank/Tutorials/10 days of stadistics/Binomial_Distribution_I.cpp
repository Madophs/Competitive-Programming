#include <bits/stdc++.h>

using namespace std;

double binomialCoefficients(int n, int k){
	double res = 1.0;
	if(k > n-k) k = n-k;
	for(int x=0; x < k; x++){
		res*=(double)(n-x);
		res/=(double)(x+1);
	}
	return res;
}

double binomialDistribution(int x, int n, double p){
	double q = 1.0-p;
	return binomialCoefficients(n,x)*pow(p,x)*pow(q,n-x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(3);
	cout.fixed;
	double a,b,res=0,p;
	cin>>a>>b;
	p = a/(a+b);
	for(int x=3; x<=6; x++){
		res+=binomialDistribution(x,6,p);
	}
	cout<<res<<endl;
	return 0;
}