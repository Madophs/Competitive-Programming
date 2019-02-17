#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int i,j,q,test=0;
	while(cin>>str){
		cin>>q;
		cout<<"Case "<<++test<<":\n";
		while(q--){
			cin>>i>>j;
			string temp = str.substr(min(i,j),max(i,j)-min(i,j)+1);
			if(temp == string(temp.length(),'1') || temp == string(temp.length(),'0')){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}
	}
	return 0;
}