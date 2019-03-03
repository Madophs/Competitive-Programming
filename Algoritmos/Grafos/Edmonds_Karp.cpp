#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

class Graph{
	public:
		unordered_map<int, unordered_map<int,int> >table;
		vector<int> parent;
		int flow;
		Graph(int nodes){
			unordered_map<int,int> temp;
			for(int x=0; x<nodes; x++) table[x] = temp;
		}

		void insert(int a, int b, int capacity){
			table.find(a)->second[b] = capacity;
			table.find(b)->second[a] = capacity;
		}
		void augment(int s,int v, int minEdge=INF){
			if(v == s){
				flow = minEdge;
				return;
			}else if(parent[v]!=-1){
				int parentEdgeValue = table.find(parent[v])->second.find(v)->second;
				augment(s,parent[v], min(minEdge, parentEdgeValue));
				table.find(parent[v])->second.find(v)->second-=flow;
				table.find(v)->second.find(parent[v])->second+=flow;
			}
		}
		int edmodsKarp(int s, int t){
			int maxFlow = 0;
			while(true){
				flow = 0;
				vector<int> dist(table.size(), INF);
				parent.assign(table.size(),-1);
				queue<int> q;
				q.push(s);
				dist[s] = 0;
				while(!q.empty()){
					int u = q.front();
					q.pop();
					if(u == t) break;
					auto adj = table.find(u)->second;
					for(auto v = adj.begin(); v!=adj.end(); v++){
						if(dist[v->first] == INF && v->second>0){
							dist[v->first] = dist[u] + 1;
							parent[v->first] = u;
							q.push(v->first);
						}
					}
				}
				augment(s,t);
				if(flow==0) break;
				maxFlow += flow;
			}
			return maxFlow;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numNodes, numEdges, capacity,a,b, start, sink;
	cin>>numNodes>>numEdges;
	Graph g(numNodes);
	while(numEdges-- && cin>>a>>b>>capacity) g.insert(a,b,capacity);
	cin>>start>>sink;
	cout<<"Max flow: "<<g.edmodsKarp(start,sink)<<endl;
	return 0;
}

/*

Test case
correct result: 28

10 14
0 1 5
0 9 7
0 2 8
0 3 3
0 4 3
0 5 7
1 9 4
2 9 9
3 6 1
4 7 4
5 8 6
6 9 1
7 9 6
8 9 5
0 9



*/