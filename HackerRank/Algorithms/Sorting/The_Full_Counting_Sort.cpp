#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector< pair<int,vector<string> > > pairs(100,make_pair(0,vector<string>()));
	int n,x;
	string s;
	cin>>n;
	int half = n/2;
	while(n-- && cin>>x>>s){
		if(n>=half)s="-";
		pairs[x].second.push_back(s);
	}
	for(int x=0; x<100;x++){
		for(int i = 0; i<pairs[x].second.size(); i++){
			cout<<pairs[x].second[i]<<" ";
		}
	}
	return 0;
}