#include <bits/stdc++.h>

using namespace std;

const int limit = 1e3+7;
vector<int> primes;

void generatePrimes(){
	bitset<1007> sieve;
	sieve.set();
	primes.emplace_back(1);
	for(int i = 2; i<limit; i++){
		if(!sieve.test(i)) continue;
		primes.emplace_back(i);
		for(int j = i<<1; j<limit; j+=i){
			sieve.reset(j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, primesToPrint;
	generatePrimes();
	while(cin>>n>>primesToPrint){
		cout<<n<<" "<<primesToPrint<<":";
		int pos = lower_bound(primes.begin(), primes.end(),n)-primes.begin();
		pos += primes[pos] == n;
		int center = (pos+1)/2-1;
		primesToPrint-=(pos&1);
		int low = (center-primesToPrint)+!(pos&1), high = center + primesToPrint;
		if(low < 0 || high > pos) low = 0, high = pos;
		for(int i = low; i<=high && primes[i]<=n && primes[i]; i++){
			cout<<" "<<primes[i];
		}
		cout<<"\n\n";
	}
	return 0;
}
