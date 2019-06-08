#include <bits/stdc++.h>

using namespace std;

const int limit = 1e6+7;

set<int> primes;
void generatePrimes(){
	bitset<1000007> table;
	table.set();
	for(int i = 2; i<limit; i++){
		if(!table.test(i)) continue;
		primes.insert(i);
		for(int j = i<<1; j<limit; j+=i){
			table.reset(j);
		}
	}
}

pair<int,int> goldbachsConjecture(int number){
	int a = -1, b = -1;
	for(auto iter = primes.begin(); iter!=primes.end(); iter++){
		if(*iter > number) break;
		int possible = number - *iter;
		if(primes.find(possible) != primes.end()){
			a = *iter;
			b = possible;
			break;
		}
	}
	return {a,b};
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	generatePrimes();
	while(cin>>n && n){
		pair<int,int> ans = goldbachsConjecture(n);
		if(ans.first < 0){
			cout<<"‘Goldbach's conjecture is wrong.\n";
		}else{
			cout<<n<<" = "<<ans.first<<" + "<<ans.second<<"\n";
		}
	}
	return 0;
}
