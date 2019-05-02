#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		vector< vector<int> > nodes;
		vector<int> inDegree;
		Graph(int events){
			nodes.assign(events+1,vector<int>());
			inDegree.assign(events+1,0);
		}
		void connectNodes(int a, int b){
			nodes[a].emplace_back(b);
			inDegree[b]++;
		}
		int ways(){
			queue<int> order;
			order.push(0);
			int countWays[nodes.size()+1];
			memset(countWays, 0, sizeof countWays);
			countWays[0] = 1;
			while(!order.empty()){
				int u = order.front();
				order.pop();
				for(auto v = nodes[u].begin(); v!=nodes[u].end(); v++){
					countWays[*v] += countWays[u];
					--inDegree[*v];
					if(inDegree[*v] == 0)
						order.push(*v);
				}
			}
			return countWays[nodes.size()-1];
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int events, numNodes, node, jumps = 0;
	while(cin>>events){
		if(jumps++) cout<<"\n";
		Graph g(events);
		for(int v = 0; v<events; v++){
			cin>>numNodes;
			if(!numNodes){
				g.connectNodes(v,events);
			}else{
				while(numNodes-- && cin>>node){
					g.connectNodes(v,node);
				}
			}
		}
		cout<<g.ways()<<"\n";
	}
	return 0;
}