#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m, score;
	cin>>n;
	map<int, int> scores;
	for(int x=0; x<n; x++){
		cin>>score;
		auto aux = scores.find(score);
		if(aux==scores.end()){
			scores[score] = scores.size()+1;
		}
	}
	auto iter = scores.begin(), last = scores.end();
	--last;
	cin>>m;
	for(int x=0; x<m; x++){
		cin>>score;
		while(1){
			if(iter==scores.end() || score>=last->first){
				cout<<"1\n";
				break;
			}
			if(score<=iter->first){
				cout<<iter->second+(score<iter->first)<<endl;
				break;
			}else{
				++iter;
			}
		}
		
	}
	return 0;
}