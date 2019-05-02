#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
	Graph(int size){
		adj.assign(size+1,vector<int>());
	}
	void connect(int a, int b){
		adj[a].push_back(b);
	}
	void dfs(int u){
		visited[u] = true;
		for(int v = 0; v<adj[u].size(); v++){
			connected[adj[u][v]] = true;
			if(!visited[adj[u][v]]){
				dfs(adj[u][v]);
			}
		}
	}
	void getInaccessibles(int s){
		connected.assign(adj.size(),false), visited.assign(adj.size(),false);
		dfs(s);
		vector<int> ans;
		for(int i = 1; i<connected.size(); i++){
			if(!connected[i]){
				ans.push_back(i);
			}
		}
		cout<<ans.size();
		for(int i = 0; i<ans.size(); i++){
			cout<<" "<<ans[i];
		}
		cout<<"\n";
	}
	vector<vector<int>> adj;
	vector<bool> connected, visited;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes,s,v;
	while(cin>>nodes && nodes){
		Graph g(nodes);
		while(cin>>s && s){
			while(cin>>v && v){
				g.connect(s,v);
			}
		}
		cin>>s;
		while(s-- && cin>>v){
			g.getInaccessibles(v);
		}
	}
	return 0;
}