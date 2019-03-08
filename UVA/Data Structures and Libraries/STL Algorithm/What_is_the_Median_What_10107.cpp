#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long num;
	priority_queue<long, vector<long>, less<long> > lowers;
	priority_queue<long, vector<long>, greater<long> > uppers;
	while(cin>>num){
		if(lowers.size()==uppers.size()){
			if(lowers.empty()){
				lowers.push(num);
			}else if (num > lowers.top()){
				uppers.push(num);
				lowers.push(uppers.top());
				uppers.pop();
			}else{
				lowers.push(num);
			}		
		}else{
			if(num >= lowers.top()){
				uppers.push(num);
			}else{
				lowers.push(num);
				uppers.push(lowers.top());
				lowers.pop();
			}
		}
		int size = lowers.size() + uppers.size();
		if(size & 1){
			cout<<lowers.top()<<endl;
		}else{
			cout<<(lowers.top()+uppers.top())/2<<endl;
		}
	}		
	return 0;
}
