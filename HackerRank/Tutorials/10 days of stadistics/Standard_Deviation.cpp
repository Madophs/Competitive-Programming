#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	double sum=0,mean=0,res=0;
	cin>>n;
	double numbers[n];
	for(int x=0; x<n; x++){
		cin>>numbers[x];
		sum+=numbers[x];
	}
	mean = sum/(double)(n);
	sum = 0;
	for(int x=0; x<n; x++)sum+=pow(numbers[x]-mean,2);
	res = sqrt(sum/(double)(n));
	cout<<setprecision(1)<<fixed<<res<<endl;
	return 0;
}