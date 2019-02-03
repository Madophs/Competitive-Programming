#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string line;
	while(getline(cin,line) && !line.empty()){
		for(auto iter = line.begin(); iter!=line.end(); iter++)cout<<((char)(*iter-7));
		cout<<"\n";
	}
	return 0;
}
