#include <bits/stdc++.h>

using namespace std;
long int factorial(int num){
	if(num==1 || num==0)return 1;
	long int res = 1;
	for(int x = 2; x<=num; x++)res*=x;
	return res;
}
double poissonDistribution(int k, double mean){
	return (pow(mean,k)*exp(-mean))/(double)(factorial(k));
}
int main(){
	ios_base::sync_with_stdio(false);
	double mean,k;
	cin>>mean>>k;
	cout<<setprecision(3)<<fixed<<poissonDistribution(k,mean)<<endl;
	return 0;
}