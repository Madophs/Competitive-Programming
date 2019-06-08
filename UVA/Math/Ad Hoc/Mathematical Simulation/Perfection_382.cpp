#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void getPrimes(){
	bitset<60005> boolPrimes;
	boolPrimes.set();
	for(int i = 2; i<60005; i++){
		if(!boolPrimes.test(i)) continue;
		for(int j = i<<1; j < 60005; j+=i){
			boolPrimes.reset(j);
		}
	}
	for(int i = 2; i<60005; i++){
		if(boolPrimes.test(i)) primes.emplace_back(i);
	}
}

string trialDivision(int num){
	int i = 0, sum = 0, limit = num>>1, auxPrime = 1;
	unordered_set<int> results;
	while(primes[i]<=limit ){
		if(num % (primes[i]) == 0){
			if(num % (primes[i]*auxPrime) == 0){
				results.insert(num/(primes[i]*auxPrime));
				results.insert(primes[i]);
			}
			if(primes[i]*auxPrime>=num) ++i, auxPrime = 0;
			++auxPrime;
		}else{
			++i;
			auxPrime = 1;
		}
	}
	for(auto it = results.begin(); it!=results.end(); it++) sum += *it;
	if(sum == num) return "PERFECT";
	if(sum > num) return "ABUNDANT";
	return "DEFICIENT";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	vector<int> numbers;
	getPrimes();
	while(cin>>num && num) numbers.emplace_back(num);
	cout<<"PERFECTION OUTPUT\n";
	for(int i = 0; i<numbers.size(); i++){
		string ans = trialDivision(numbers[i]);
		cout<<setw(5)<<setfill(' ')<<right<<numbers[i]<<"  "<<ans<<"\n";
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}