#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int frost,value;
	while(cin>>frost && frost){
		unordered_map<string,int> dic;
		int maxConformity = 0;
		while(frost--){
			vector<int> vec;
			for(int i = 0; i < 5 && cin>>value; i++) vec.push_back(value);
			sort(vec.begin(), vec.end());
			string line = "";
			for(int i = 0; i<vec.size(); i++){
				line+=to_string(vec[i])+" ";
			}
			if(dic.find(line) == dic.end()){
				dic[line] = 1;
			}else{
				++dic.find(line)->second;
			}
			maxConformity = max(maxConformity,dic.find(line)->second);
		}
		int ans = 0;
		for(auto it = dic.begin(); it!=dic.end(); it++){
			ans += it->second == maxConformity ? it->second: 0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
