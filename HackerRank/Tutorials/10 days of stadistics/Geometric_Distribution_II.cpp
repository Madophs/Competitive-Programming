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

double geometricDistribution(int n, double p){
	double q = 1-p;
	return pow(q,n-1)*p;
}
int main(){
	ios_base::sync_with_stdio(false);
	double numerator, denominator,probability,n,res=0;
	cin>>numerator>>denominator>>n;
	probability = numerator/denominator;
	for(int x=0; x<=n; x++){
		res += geometricDistribution(x,probability);
	}
	cout<<setprecision(3)<<fixed<<res<<endl;
	return 0;
}