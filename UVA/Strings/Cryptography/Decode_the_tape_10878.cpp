#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, separator(11,'_'), ans = "";
	cin>>line;
	cin.ignore();
	while(getline(cin,line) && line!=separator){
		string code = line.substr(1,9);
		code.erase(code.begin()+5);
		int decimalValue = 0;
		for(int i = code.length()-1, bit = 0; i>=0; i--, bit++){
			if(code[i] == 'o') decimalValue|=1<<bit;
		}
		ans+=(char)(decimalValue);	
	}
	cout<<ans;
	return 0;
}