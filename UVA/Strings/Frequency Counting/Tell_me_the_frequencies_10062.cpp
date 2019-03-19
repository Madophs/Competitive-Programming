#include <bits/stdc++.h>

using namespace std;

bool mdsSort(pair<int,int> a, pair<int,int> b){
	if(a.second < b.second) return true;
	return a.second == b.second && a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	const int limit = 255;
	int frec[limit];
	int test = 0;
	while(getline(cin,line)){
		if(test--) cout<<"\n";
		memset(frec,0,sizeof frec);
		for(auto i = line.begin(); i!=line.end(); i++){

			++frec[*i];
		}
		vector< pair<int,int> > ans; 
		for(int i = 32; i<limit-128; i++){
			if(frec[i]) ans.emplace_back(make_pair(i,frec[i]));
		}
		sort(ans.begin(), ans.end(),mdsSort);
		for(int i = 0; i<ans.size(); i++){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}
	return 0;
}