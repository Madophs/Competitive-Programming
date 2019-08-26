#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cases, shorter, larger;
	string bytes;
	unordered_map<string, int> table;
	unordered_multimap<int, string> byteSize;
	set<int> repeatedSizes;
	cin>>cases;
	cin.ignore();
	getline(cin, bytes);
	while(cases--){
		table.clear();
		byteSize.clear();
		repeatedSizes.clear();
		shorter = (int)1e9, larger = 0;
		while(getline(cin, bytes) && !bytes.empty()){
			shorter = min(shorter, (int)bytes.length());
			larger = max(larger, (int)bytes.length());
			byteSize.insert(make_pair((int)bytes.length(), bytes));
		}
		int size = shorter + larger;
		string str1, str2;
		for(auto value : byteSize){
			int diff = abs(size - value.first);
			if(repeatedSizes.count(value.first) && repeatedSizes.count(diff)) continue;
			auto range = byteSize.equal_range(value.first);
			auto range2 = byteSize.equal_range(diff);
			for(auto it = range.first; it != range.second; it++){
				for(auto iter = range2.first; iter != range2.second; iter++){
					if(iter == it) continue;
					str1 = it->second + iter->second;
					str2 = iter->second + it->second;
					if(table.count(str1)) table.find(str1)->second++;
					else table[str1] = 1;
					if(table.count(str2)) table.find(str2)->second++;
					else table[str2] = 1;
				}
			}
			repeatedSizes.insert(diff);
			repeatedSizes.insert(value.first);
		}
		pair<string, int> ans("", 0);
		for(auto val : table){
			if(val.second > ans.second && val.first.length() == size){
				ans.first = val.first;
				ans.second = val.second;
			}
		}
		cout<<ans.first<<"\n";
		if(cases) cout<<"\n";
	}	
	return 0;
}
