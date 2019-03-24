#include <bits/stdc++.h>

using namespace std;

unordered_set<int> primes;

void getPrimes(){
	bitset<2005> sieve;
	sieve.set();
	for(int i = 2; i<=2003; i++){
		if(!sieve.test(i)) continue;
		primes.insert(i);
		for(int j = 2*i; j<=2003; j+=i){
			sieve.reset(j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getPrimes();
	int tests;
	int numbers[10], lower[27], upper[27];
	string line;
	cin>>tests;
	for(int t = 1; tests-- && cin>>line; t++){
		memset(numbers,0,sizeof numbers);
		memset(lower,0,sizeof lower);
		memset(upper,0,sizeof upper);
		for(int i = 0; i<line.length(); i++){
			if(isdigit(line[i])){
				++numbers[line[i]-'0'];
			}else if(line[i]>='a' && line[i]<='z'){
				++lower[line[i]-'a'];
			}else{
				++upper[line[i]-'A'];
			}
		}
		string ans = "";
		for(int i = 0; i<10; i++){
			if(!numbers[i]) continue;
			if(primes.find(numbers[i]) != primes.end()){
				ans+=(char)(i+'0');
			}
		}
		for(int i = 0; i<26; i++){
			if(!upper[i]) continue;
			if(primes.find(upper[i]) != primes.end()){
				ans+=(char)(i+'A');
			}
		}
		for(int i = 0; i<26; i++){
			if(!lower[i]) continue;
			if(primes.find(lower[i]) != primes.end()){
				ans+=(char)(i+'a');
			}
		}
		cout<<"Case "<<t<<": "<<(ans.empty()?"empty\n":ans+"\n");
	}
	return 0;
}