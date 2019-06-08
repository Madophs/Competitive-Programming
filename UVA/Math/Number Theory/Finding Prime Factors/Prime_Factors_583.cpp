#include <bits/stdc++.h>

using namespace std;

const int limit = 5e4;

vector<int> primes;

void generatePrimes(){
	bitset<50005> table;
	for(long long i = 2; i<=limit; i++){
		if(table.test(i)) continue;
		primes.emplace_back(i);
		for(long long j = i*i; j<=limit; j+=i){
			table.set(j);
		}
	}
}

void findFactors(int number){
	vector<int> factors;
	if(number < 0) factors.emplace_back(-1);
	long long index = 0, factor = primes[index], originalNumber = number;
	number = abs(number);
	while(factor*factor <= number){
		while(number % factor == 0){
			number/=factor;
			factors.emplace_back(factor);
		}
		factor = primes[++index];
	}
	if(number != 1) factors.emplace_back(number);
	cout<<originalNumber<<" =";
	for(int i = 0; i<factors.size(); i++){
		if(i) cout<<" x";
		cout<<" "<<factors[i];
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long number;
	generatePrimes();
	while(cin>>number && number){
		findFactors(number);
	}
	return 0;
}
