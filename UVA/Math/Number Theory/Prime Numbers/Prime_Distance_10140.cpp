#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int) 1e7;

vector<int> primes;
bitset<10000007UL> table;

void generatePrimes(){
	for(long long i = 2; i<=MAX_N; i++){
		if(table.test(i)) continue;
		primes.emplace_back(i);
		for(long long j = i*i; j<=MAX_N; j+=i){
			table.set(j);
		}
	}
}

bool isPrime(long long number){
	if(number <= MAX_N) return !table[number];
	long long limit = sqrtl(number);
	for(int i = 0; i<primes.size(); i++){
		if(number % primes[i] == 0) return false;
		if(primes[i] > limit) return true;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	pair<int,int> closest, distant;
	generatePrimes();
	while(cin>>a>>b){
		closest = make_pair(0, 1e9);
		distant = make_pair(0,0);
		if(b <= MAX_N){
			int pos = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
			int limit = lower_bound(primes.begin(), primes.end(), b) - primes.begin();
			if(primes[limit] == b) ++limit;
			for(int i = pos; i<limit-1; i++){
				if(primes[i+1] - primes[i] < closest.second - closest.first){
					closest.first = primes[i];
					closest.second = primes[i+1];
				}
				if(primes[i+1] - primes[i] > distant.second - distant.first){
					distant.first = primes[i];
					distant.second = primes[i+1];
				}
			}
		}else{
			int current = -1, prev = -1;
			if(!(a & 1)) ++a;
			for(long long i = a; i<=b; i+=2){
				if(isPrime(i)){
					prev = current;
					current = i;
					if(prev != -1){
						if(current - prev < closest.second - closest.first){
							closest.first = prev;
							closest.second = current;
						}
						if(current - prev > distant.second - distant.first){
							distant.first = prev;
							distant.second = current;
						}
					}
				}
			}
		}
		if(closest.second == (int)1e9){
			cout<<"There are no adjacent primes.\n";
		}else{
			cout<<closest.first<<","<<closest.second<<" are closest, "<<distant.first<<","<<distant.second<<" are most distant.\n";
		}
	}
	return 0;
}
