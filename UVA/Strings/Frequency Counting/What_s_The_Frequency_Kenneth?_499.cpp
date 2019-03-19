#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	map<char,int> frec;
	while(getline(cin,line)){
		frec.clear();
		for(int i = 0; i<line.length(); i++){
			if(!isalpha(line[i])) continue;
			if(frec.find(line[i]) == frec.end()){
				frec[line[i]] = 1;
			}else{
				++frec.find(line[i])->second;
			}
		}
		string ans = "";
		int maxValue = 0;
		for(auto it = frec.begin(); it!=frec.end(); it++){
			if(it->second >= maxValue){
				if(it->second > maxValue){
					ans = it->first;
				}else{
					ans += it->first;
				}
				maxValue = it->second;
			}
		}
		cout<<ans<<" "<<maxValue<<"\n";
	}
	return 0;
}