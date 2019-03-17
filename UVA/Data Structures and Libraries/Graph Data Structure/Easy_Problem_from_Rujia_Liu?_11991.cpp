#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes, queries,val,k;
	while(cin>>nodes>>queries){
		unordered_map<int, vector<int>> adj;
		for(int i = 1; i<=nodes && cin>>val; i++){
			if(adj.find(val) == adj.end()){
				vector<int> temp(1,i);
				adj[val] = temp;
			}else{
				adj.find(val)->second.push_back(i);
			}
		}
		while(queries-- && cin>>k>>val){
			if(adj.find(val) != adj.end()){
				if(k <= adj.find(val)->second.size()){
					cout<<adj.find(val)->second[k-1]<<"\n";
				}else{
					cout<<"0\n";
				}
			}else{
				cout<<"0\n";
			}
		}
	}
	return 0;
}