#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, val;
	string message;
	bitset<210> taken;
	unordered_map<int, pair<int,int>> hash;
	vector<vector<int>> cycles;
	while(cin>>n && n){
		vector<int> indexes;
		for(int i = 0; i < n && cin>>val; ++i){
			indexes.emplace_back(val);
		}
		taken.reset();
		hash.clear();
		cycles.clear();
		for(int i = 0, row = 0; i < n; ++i){
			if(taken.test(indexes[i])) continue;
			int index = indexes[i];
			cycles.emplace_back(vector<int>());
			while(!taken.test(index)){
				taken.set(index);
				cycles.back().emplace_back(index);
				hash[index] = make_pair(row, cycles.back().size()-1);
				index = indexes[index-1];
			}
			++row;
		}
		while(cin>>k && k){
			cin.ignore();
			getline(cin,message);
			if(message.length() < n){
				string spaces(n - (int) message.length(), ' ');
				message += spaces;
			}
			string decodedMessage(n,' ');
			for(int i = 0; i < n; ++i){
				int row = hash.find(indexes[i])->second.first;
				int col = hash.find(indexes[i])->second.second;
				int pos = ((k+col) % (int)cycles[row].size())-1;
				if(pos == -1) pos = cycles[row].size()-1;
				decodedMessage[cycles[row][pos]-1] = message[i];
			}
			cout<<decodedMessage<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
