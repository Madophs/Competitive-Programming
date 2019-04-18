#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		vector<vector<int>> nodes;
		Graph(int size){
			nodes.assign(size,vector<int>());
		}
		void connectNodes(int a, int b){
			nodes[a].emplace_back(b);
		}
		void printBestPlaces(){
			int min_neighbors = 1e9;
			vector<int> ans;
			for(int i = 0; i<nodes.size(); i++){
				if(min_neighbors >= nodes[i].size()){
					if(min_neighbors > nodes[i].size()){
						ans.clear();
						ans.emplace_back(i+1);
					}else{
						ans.emplace_back(i+1);
					}
					min_neighbors = (int)nodes[i].size();
				}
			}
			for(int i = 0; i<ans.size(); i++){
				if(i) cout<<" ";
				cout<<ans[i];
			}
			cout<<"\n";
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, size,i, j;
	string line;
	cin>>tests;
	while(tests--){
		cin>>size;
		Graph g(size);
		cin.ignore();
		for(i = 0; i<size; i++){
			getline(cin,line);
			stringstream ss(line);
			while(ss>>j) g.connectNodes(i,j);
		}
		g.printBestPlaces();
	}
	return 0;
}