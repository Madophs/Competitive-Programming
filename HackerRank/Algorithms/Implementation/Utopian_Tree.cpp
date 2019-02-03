#include <bits/stdc++.h>

using namespace std;

int answers[62];

void simulations(){
	answers[0] = 1;
	for(int x=1; x<62; x++)answers[x] = x&1?answers[x-1]*2: answers[x-1]+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	simulations();
	int t,n;
	cin>>t;
	while(t-- && cin>>n)cout<<answers[n]<<endl;
	return 0;
}