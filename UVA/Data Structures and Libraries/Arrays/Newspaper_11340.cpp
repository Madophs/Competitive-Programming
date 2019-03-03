#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, letters, cents, lines,sum;
	double ans;
	string line;
	char character;
	cin>>test;
	while(test--){
		cin>>letters;
		unordered_map<char,int> values;
		while(letters-- && cin>>character>>cents) values[character] = cents;
		cin>>lines;
		cin.ignore();
		ans = sum = 0;
		while(lines-- && getline(cin,line)){
			for(auto it = line.begin(); it!=line.end(); it++){
				if(values.find(*it) == values.end())continue;
				sum+=values.find(*it)->second;
			}
		}
		ans = sum/100.0;
		cout<<fixed<<setprecision(2)<<ans<<"$\n";
	}
	return 0;
}