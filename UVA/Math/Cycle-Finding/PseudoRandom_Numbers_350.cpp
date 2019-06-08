#include <bits/stdc++.h>

using namespace std;

int z, i, m, l;
int nextPseudoRandomNumber(int seed){
	return (z*seed+i) % m;
}

int floyd(int seed){
	int tortoise = nextPseudoRandomNumber(seed), hare = nextPseudoRandomNumber(nextPseudoRandomNumber(seed));
	while(tortoise != hare){
		tortoise = nextPseudoRandomNumber(tortoise);
		hare = nextPseudoRandomNumber(nextPseudoRandomNumber(hare));
	}
	int mu = 0;
	hare = seed;
	while(hare != tortoise)
		hare = nextPseudoRandomNumber(hare),
		tortoise = nextPseudoRandomNumber(tortoise),
		++mu;
	int cycleLength = 1;
	hare = nextPseudoRandomNumber(tortoise);
	while(hare != tortoise) hare = nextPseudoRandomNumber(hare), ++cycleLength;
	return cycleLength;
}

int brent(int seed){
	int p1 = nextPseudoRandomNumber(seed);
	int p2 = nextPseudoRandomNumber(p1);
	int cycleLength = 1, power = 1;
	while(p1 != p2){
		while(cycleLength == power){
			power *= 2;
			cycleLength = 0;
			p1 = p2;
		}
		p2 = nextPseudoRandomNumber(p2);
		++cycleLength;
	}
	return cycleLength;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int caseNumber = 0;
	while(cin>>z>>i>>m>>l && (z || i || m || l)){
		cout<<"Case "<<++caseNumber<<": ";
		cout<<brent(l)<<"\n";
	}
	return 0;
}
