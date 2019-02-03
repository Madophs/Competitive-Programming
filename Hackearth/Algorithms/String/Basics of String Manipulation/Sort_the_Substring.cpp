#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, i, j;
	string str;
	cin>>t;
	while(t--  && cin>>str>>i>>j){
		sort(str.begin()+i,str.begin()+(j+1),[&](char a, char b){
			return a>b;
		});
		cout<<str<<'\n';
	}
	return 0;
}