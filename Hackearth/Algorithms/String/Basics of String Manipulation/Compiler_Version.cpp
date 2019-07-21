#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	while(getline(cin,line)){
		for(int i = 0; i < line.length()-1; ++i){
			if(line[i] == '/' && line[i+1] == '/') break;
			if(line[i] == '-' && line[i+1] == '>'){
				line.replace(i, 2, ".");
				--i;
			}
		}
		cout<<line<<"\n";
	}
	return 0;
}
