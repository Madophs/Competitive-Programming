#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size, value, ans = 1e9;
	vector<pair<int,int>> vec;
	cin>>size;
	for(int i = 0; i < size && cin>>value; ++i){
		vec.emplace_back(make_pair(value,i));
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size()-1; ++i){
		if(vec[i].first != vec[i+1].first) continue;
		ans = min(ans, abs(vec[i].second-vec[i+1].second));
	}
	if(ans == (int)1e9){
		cout<<-1<<"\n";
	}else{
		cout<<ans<<"\n";
	}
	return 0;
}
