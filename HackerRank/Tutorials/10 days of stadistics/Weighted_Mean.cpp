#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int size;
	double sum=0,sumWeights=0,weighted_mean;
	cin>>size;
	int values[size], weights[size];
	for(int x=0; x<size; x++)cin>>values[x];
	for(int x=0; x<size; x++){
		cin>>weights[x];
		sum+= static_cast<double>(values[x])*static_cast<double>(weights[x]);
		sumWeights+=(double)weights[x];
	}
	weighted_mean = sum/sumWeights;
	cout<<setprecision(1)<<fixed<<weighted_mean<<endl;
	return 0;
}