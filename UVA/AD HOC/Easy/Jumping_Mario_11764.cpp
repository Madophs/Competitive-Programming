#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,c=0,walls=0;
	cin>>t;
	while(t--){
		cin>>walls;
		int var,high=0,low=0,current=1e9;
		if(walls==1){
			cin>>var;
			cout<<"Case "<<++c<<": 0 0\n";
			continue;
		}
		while(walls--){
			cin>>var;
			if(current==1e9){
				current=var;
				continue;
			}
			if(var>current){
				++high;
				current=var;
			}else if(var<current){
				++low;
				current=var;
			}
		}
		cout<<"Case "<<++c<<": "<<high<<" "<<low<<"\n";
	}
    return 0;
}
