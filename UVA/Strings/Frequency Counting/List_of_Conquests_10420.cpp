#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string line, country;
	map<string,int> conquest;
	cin>>tests;
	cin.ignore();
	while(tests--){
		getline(cin,line);
		stringstream ss(line);
		ss>>country;
		if(conquest.find(country) == conquest.end()){
			conquest[country] = 1;
		}else{
			++conquest.find(country)->second;
		}
	}
	for(auto i = conquest.begin(); i!=conquest.end(); i++){
		cout<<i->first<<" "<<i->second<<"\n";
	}
	return 0;
}