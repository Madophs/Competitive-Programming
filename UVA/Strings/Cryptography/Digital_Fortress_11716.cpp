#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string line;
	cin>>tests;
	cin.ignore();
	while(tests-- && getline(cin,line)){
		int root = (int)floor(sqrt(line.length()));
		if(line.length()!=root*root){
			cout<<"INVALID\n";
		}else{
			string ans = "";
			for(int i = 0; i<root; i++){
				for(int j = i; j<line.length(); j+=root) ans+=line[j];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}