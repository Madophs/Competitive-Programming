#include <bits/stdc++.h>

using namespace std;

vector<int> getPrimes(int n=10000){
	vector<bool> num(n,true);
	vector<int> ret;
	num[0] = false;
	num[1] = false;
	for(int x=2; x<n; x++){
		if(!num[x])continue;
		for(int y=2*x; y<n; y+=x){
			num[y] = false;
		}
	}
	for(int x=2; x<n; x++){
		if(num[x]) ret.push_back(x);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,val;
	vector< stack<int> > a(1,stack<int>()),b(1,stack<int>());
	cin>>n>>q;
	vector<int> primes = getPrimes();
	while(n-- && cin>>val) a[0].push(val);
	for(int x=0; x<q; x++){
		if(a[x].empty())break;
		a.push_back(stack<int>());
		b.push_back(stack<int>());
		while(!a[x].empty()){
			if(a[x].top()%primes[x]==0){
				b[x].push(a[x].top());
				a[x].pop();
			}else{
				a[x+1].push(a[x].top());
				a[x].pop();
			}
		}
	}
	for(auto iter = b.begin(); iter!=b.end(); iter++){
		auto ref = *iter;
		while(!ref.empty()){
			cout<<ref.top()<<endl;
			ref.pop();
		}
	}
	for(auto iter = a.rbegin(); iter!=a.rend(); iter++){
		auto ref = *iter;
		if(ref.empty())break;
		while(!ref.empty()){
			cout<<ref.top()<<endl;
			ref.pop();
		}
	}
	return 0;
}