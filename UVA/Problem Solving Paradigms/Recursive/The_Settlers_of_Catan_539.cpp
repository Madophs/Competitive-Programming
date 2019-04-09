#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
	vector< vector<pair<int, bool>> > nodes;
	Graph(int size){
		for(int i = 0; i<size; i++) nodes.emplace_back(vector<pair<int,bool>>());
	}
	void connectNodes(int a, int b){
		nodes[a].emplace_back(make_pair(b,true));
		nodes[b].emplace_back(make_pair(a,true));
	}
	void disconnectBidirectionalEdge(int v, int u){
		for(int i = 0; i<nodes[v].size(); i++){
			if(nodes[v][i].first == u){
				nodes[v][i].second = false;
			}
		}
	}
	void connectBidirectionalEdge(int v, int u){
		for(int i = 0; i<nodes[v].size(); i++){
			if(nodes[v][i].first == u){
				nodes[v][i].second = true;
			}
		}
	}
	int largestRoad(){
		int largestDistance = 0;
		for(int i = 0; i<nodes.size(); i++){
			largestDistance = max(largestDistance,dfs(i));
		}
		return largestDistance;
	}
	int dfs(int u, int distance = 0){
		int ret = 0;
		for(int v = 0; v<nodes[u].size(); v++){
			if(nodes[u][v].second){
				nodes[u][v].second = false;
				disconnectBidirectionalEdge(nodes[u][v].first,u);
				ret = max(ret,dfs(nodes[u][v].first, distance + 1));
				connectBidirectionalEdge(nodes[u][v].first,u);
				nodes[u][v].second = true;
			}
		}
		return max(ret,distance);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numNodes, numRoads, a,b;
	while(cin>>numNodes>>numRoads && (numNodes || numRoads)){
		Graph g(numNodes);
		while(numRoads-- && cin>>a>>b) g.connectNodes(a,b);
		cout<<g.largestRoad()<<"\n";
	}
	return 0;
}