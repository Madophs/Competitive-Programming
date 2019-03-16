#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		Graph(int size){
			incoming.assign(size+1,0);
			nodes.assign(size+1,vector<int>());
			visited.assign(size+1,false);
		}
		void insertEdge(int a, int b){
			nodes[a].push_back(b);
			incoming[b]++;
		}
		vector<int> taskOrdering(){
			queue<int> q;
			vector<int> res;
			for(int i = 1; i<incoming.size(); i++){
				if(!incoming[i]) q.push(i);
			}
			while(!q.empty()){
				int v = q.front();
				q.pop();
				res.emplace_back(v);
				visited[v] = true;
				for(int u = 0; u<nodes[v].size(); u++){
					if(!visited[nodes[v][u]]){
						--incoming[nodes[v][u]];
						if(!incoming[nodes[v][u]]){
							q.push(nodes[v][u]);
						}
					}
				}
			}
			return res;
		}
	private:
		vector<int> incoming;
		vector<vector<int>> nodes;
		vector<bool> visited;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int task, relations, a, b;
	while(cin>>task>>relations && (task || relations)){
		Graph g(task);
		while(relations-- && cin>>a>>b) g.insertEdge(a,b);
		vector<int> ans = g.taskOrdering();
		for(int i = 0; i<ans.size(); i++){
			if(i) cout<<" ";
			cout<<ans[i];
		}
		cout<<"\n";
	}
	return 0;
}