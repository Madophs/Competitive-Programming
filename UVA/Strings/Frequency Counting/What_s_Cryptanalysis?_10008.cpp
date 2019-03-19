#include <bits/stdc++.h>

using namespace std;

bool mdsSort(pair<int,char> a, pair<int,char> b){
	if(a.first > b.first) return true;
	return a.first == b.first && a.second < a.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	int frec[27];
	string line;
	memset(frec,0,sizeof frec);
	cin>>tests;
	cin.ignore();
	while(tests-- && getline(cin,line)){
		for(auto c = line.begin(); c!=line.end(); c++){
			if(isalpha(*c)){
				++frec[toupper(*c)-'A'];
			}
		}
	}
	vector<pair<int,char>> ans;
	for(int i = 0; i<27; i++){
		if(frec[i]) ans.emplace_back(make_pair(frec[i],i+'A'));
	}
	sort(ans.begin(), ans.end(),mdsSort);
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i].second<<" "<<ans[i].first<<"\n";
	}
	return 0;
}