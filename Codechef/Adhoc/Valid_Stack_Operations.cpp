#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,ins, instructions,level;
	bool valid = true;
	cin>>t;
	while(t--){
		cin>>instructions;
		level = 0;
		valid = true;
		while(instructions--){
			cin>>ins;
			if(ins){
				++level;
			}else{
				--level;
				if(level<0)valid = false;
			}
		}
		cout<<(valid?"Valid\n":"Invalid\n");
	}
	return 0;
}