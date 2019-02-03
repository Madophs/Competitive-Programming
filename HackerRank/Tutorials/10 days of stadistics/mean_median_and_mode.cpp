#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,mode;
	double mean,median;
	cin>>n;
	int numbers[n];
	unordered_map<int,int> table;
	for(int x=0; x<n; x++){
		cin>>numbers[x];
		mean += (double)numbers[x];
		if(table.find(numbers[x])==table.end()){
			table[numbers[x]] = 1;
		}else{
			auto iter = table.find(numbers[x]);
			++iter->second;
		}
	}
	int max = -1;
	for(auto iter = table.begin(); iter!=table.end(); iter++){
		if(max < iter->second || (max==iter->second && mode>iter->first)){
			max = iter->second;
			mode = iter->first;
		}
	}
	sort(numbers,numbers+n);
	if(n&1){
		median = numbers[n/2];
	}else{
		median = (double)(numbers[n/2]+numbers[(n/2)-1])/2.0;
	}
	mean/=(double)n;
	cout<<setprecision(1)<<fixed<<mean<<endl;
	cout<<median<<endl;
	cout<<mode<<endl;
	return 0;
}