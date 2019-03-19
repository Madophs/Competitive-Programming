#include <bits/stdc++.h>

using namespace std;

map<int,char> getFibonaccies(){
	map<int, char> fibos;
	long long x = 1, y = 2, z, limit = 1L<<31;
	while(x<=limit){
		fibos[x] = '_';
		z = x+y;
		x = y;
		y = z;
	}
	return fibos;
}

void resetFibos(map<int, char> &fibos){
	for(auto it = fibos.begin(); it!=fibos.end(); it++){
		it->second = '_';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, n, val;
	string line;
	map<int,char> fibos = getFibonaccies();
	cin>>test;
	while(test--){
		cin>>n;
		vector<int> nth;
		cin.ignore();
		getline(cin,line);
		stringstream ss(line);
		while(n-- && ss>>val){
			nth.emplace_back(val);
		}
		getline(cin,line);
		for(int i = 0, j = 0; i<line.length() && j<nth.size(); i++){
			if(!isalpha(line[i]) || (line[i]>='a' && line[i]<='z')) continue;
			fibos[nth[j++]] = line[i];
		}
		string ans = "", spaces = "";
		for(auto it = fibos.begin(); it!=fibos.end(); it++){
			if(it->second=='_'){
				spaces += " ";
			}else{
				if(spaces.empty()){
					ans+=it->second;
				}else{
					ans+=spaces+it->second;
					spaces = "";
				}
			}
		}
		cout<<ans<<"\n";
		resetFibos(fibos);
	}
	return 0;
}