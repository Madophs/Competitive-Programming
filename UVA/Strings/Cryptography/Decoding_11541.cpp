#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string coded,integer,ans;
	cin>>tests;
	for(int t = 0; t<tests; t++){
		cin>>coded;
		cout<<"Case "<<t+1<<": ";
		char character;
		ans = "";
		for(int i = 0; i<coded.length();){
			character = coded[i++];
			integer = "";
			while(i < coded.length() && isdigit(coded[i])){
				integer+=coded[i++];
			}
			ans += string(atoi(integer.c_str()),character);
		}
		cout<<ans<<'\n';
	}
	return 0;
}