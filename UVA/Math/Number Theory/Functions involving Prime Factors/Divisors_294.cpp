#include <bits/stdc++.h>

using namespace std;

const int limit = 5e5;

vector<int> primes;

void generatePrimeFactors(){
	bitset<500005> table;
	table.set();
	for(int i = 2; i<=limit; i++){
		if(!table.test(i)) continue;
		primes.emplace_back(i);
		for(int j = i<<1; j<=limit; j+=i){
			table.reset(j);
		}
	}
}

int countDivisors(long long number){
	int ans = 1, power;
	long long index = 0, factor = (long long)primes[index];
	while(factor*factor <= number){
		power = 0;
		while(number % factor == 0) number /= factor, ++power;
		ans *= (power+1);
		factor = (long long) primes[++index];
	}
	if(number != 1LL) ans*=2;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	generatePrimeFactors();
	int tests;
	long long low , high;
	cin>>tests;
	while(tests-- && cin>>low>>high){
		long long ans = 0, number = low;
		for(long long i = low; i<=high; i++){
			int divisors = countDivisors(i);
			if(ans < divisors){
				ans = divisors;
				number = i;
			}
		}
		cout<<"Between "<<low<<" and "<<high<<", "<<number<<" has a maximum of "<<ans<<" divisors.\n";
	}	
	return 0;
}
