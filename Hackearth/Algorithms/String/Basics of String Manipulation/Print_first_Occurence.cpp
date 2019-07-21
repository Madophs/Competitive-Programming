#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string line, answer;
	bitset<256> firstTime;
	cin>>t;
	while(t-- && cin>>line){
		answer = "";
		firstTime.reset();
		for(char c : line){
			if(!firstTime.test((int)c)){
				answer.push_back(c);
				firstTime.set((int)c);
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}
