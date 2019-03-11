#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, members, t = 0;
	cin>>tests;
	while(tests-- && cin>>members){
		vector<int> ages(members,0);
		while(members-- && cin>>ages[members]);
		cout<<"Case "<<++t<<": "<<ages[ages.size()/2]<<"\n";
	}	
	return 0;
}