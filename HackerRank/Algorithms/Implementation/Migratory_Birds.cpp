#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,bird;
	unordered_map<int,int> table;
	cin>>n;
	while(n--){
		cin>>bird;
		auto iter = table.find(bird);
		if(iter==table.end()){
			table[bird] = 0;
		}else{
			iter->second++;
		}
	}
	int max=-1,id=inf;
	for(auto iter = table.begin(); iter!=table.end(); iter++){
		if(max<iter->second || (id>iter->first && max==iter->second)){
			id = iter->first;
			max = iter->second;
		}
	}
	cout<<id<<endl;
	return 0;
}