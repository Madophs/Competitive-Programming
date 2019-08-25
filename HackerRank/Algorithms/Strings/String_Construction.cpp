#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cases;
	string s;
	cin>>cases;
	while(cases-- && cin>>s){
		sort(s.begin(), s.end());
		auto it = unique(s.begin(), s.end());
		s.resize(distance(s.begin(), it));
		cout<<s.length()<<"\n";
	}
	return 0;
}
