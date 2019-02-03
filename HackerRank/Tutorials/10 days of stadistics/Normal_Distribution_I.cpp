#include <bits/stdc++.h>

using namespace std;

double normalDistribution(double mean, double sd,double x){
	return 0.5*(1.0+erf((x-mean)/(sd*sqrt(2.0))));
}

int main(){
	ios_base::sync_with_stdio(false);
	double mean,sd,x,a,b;
	cin>>mean>>sd>>x>>a>>b;
	cout<<setprecision(3)<<fixed<<normalDistribution(mean,sd,x)<<endl;
	cout<<setprecision(3)<<fixed<<normalDistribution(mean,sd,b)-normalDistribution(mean,sd,a)<<endl;
	return 0;
}