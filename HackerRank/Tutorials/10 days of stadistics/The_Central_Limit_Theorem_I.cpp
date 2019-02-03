#include <bits/stdc++.h>

using namespace std;

double normalDistribution(double mean, double sd,double x){
	return 0.5*(1.0+erf((x-mean)/(sd*sqrt(2.0))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double maxWeight,boxes,mean,sd;
	cin>>maxWeight>>boxes>>mean>>sd;
	cout<<setprecision(4)<<fixed<<normalDistribution(mean*boxes,sqrt(boxes)*sd,maxWeight)<<endl;
	return 0;
}