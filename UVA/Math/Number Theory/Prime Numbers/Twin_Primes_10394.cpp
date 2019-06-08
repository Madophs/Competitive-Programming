#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1e7+8e6+4e5+1e4;
vector<pair<int,int>> twinPrimes;

void generateTwinsPrimes(){
	bitset<20000007UL> table;
	int current = -1, prev = 1e9;
	for(long long i = 2; i <= LIMIT; i++){
		if(table.test(i)) continue;
		prev = current;
		current = i;
		if(current - prev == 2){
			twinPrimes.emplace_back(make_pair(prev,current));
		}
		for(long long j = i*i; j <= LIMIT; j+=i){
			table.set(j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s;
	generateTwinsPrimes();
	while(cin>>s){
		--s;
		cout<<"("<<twinPrimes[s].first<<", "<<twinPrimes[s].second<<")\n";
	}	
	return 0;
}
