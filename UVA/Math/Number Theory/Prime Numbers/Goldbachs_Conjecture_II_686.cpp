#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> primes;
	bitset< (1<<15)+10 > set;
	set.set();
	for(int x=2; x<=1<<15; x++){
		if(set[x]){
			primes.push_back(x);
			for(int y=x+x; y<=1<<15; y+=x){
				set[y]=false;
			}
		}
	}
	int num;
	while(cin>>num && num){
		int res=0;
		for(int x=0; primes[x]<num && x<primes.size(); x++){
			for(int y=x; primes[x]+primes[y]<=num && y<primes.size(); y++){
				if(primes[x]+primes[y]==num)++res;
			}
		}
		cout<<res<<"\n";
	}
    return 0;
}