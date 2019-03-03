#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		map<int, map<int,int> > table;
		int start, sink,flow, maxPossibleFlow;
		vector<int> parent;
		Graph(){
			start = 200, sink = 201, maxPossibleFlow = 0;
			map<int,int> temp;
			table[start] = temp, table[sink] = temp;
			for(int x=0; x<10; x++){
				table[x] = temp;
				insert(x,sink);
			}
		}
		void createNode(int name){
			map<int,int> temp;
			table[name] = temp;
		}
		void insert(int a, int b, int capacity=1){
			table.find(a)->second[b] = capacity;
			table.find(b)->second[a] = 0;
		}

		void augment(int v, int minEdge=1e9){
			if(v == start){
				flow = minEdge;
				return;
			}else if(parent[v]!=-1){
				int parentEdgeValue = table.find(parent[v])->second.find(v)->second;
				augment(parent[v], min(minEdge,parentEdgeValue));
				table.find(parent[v])->second.find(v)->second-=flow;
				table.find(v)->second.find(parent[v])->second+=flow;
			}
		}
		void allocation(){
			int maxFlow = 0;
			while(true){
				flow = 0;
				bitset<210> visited;
				parent.assign(210,-1);
				queue<int> q;
				q.push(start);
				visited.set(start);
				while(!q.empty()){
					int u = q.front();
					q.pop();
					if(u == sink) break;
					auto adj = table.find(u)->second;
					for(auto v = adj.begin(); v!= adj.end(); v++){
						if(!visited.test(v->first) && v->second>0){
							q.push(v->first);
							visited.set(v->first);
							parent[v->first] = u;
						}
					}
				}
				augment(sink);
				if(!flow) break;
				maxFlow+=flow;
			}
			if(maxFlow!=maxPossibleFlow){
				cout<<"!\n";
			}else{
				string strAllocation(10,'_');
				for(int x=0; x<10; x++){
					if(table.find(x)->second.find(sink)->second == 0){
						auto adj = table.find(x)->second;
						for(auto it = adj.begin(); it!=adj.end(); it++){
							if(it->second==1){
								strAllocation[x] = it->first;
								break;
							}
						}
					}
				}
				cout<<strAllocation<<'\n';
			}
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line,computers;
	char application;
	int users;
	while(getline(cin,line) && !line.empty()){
		Graph g;
		do{
			stringstream ss(line);
			ss>>application>>users>>computers;
			g.createNode(application);
			g.insert(g.start,application,users);
			g.maxPossibleFlow+=users;
			for(int x = 0; x<computers.length()-1; x++){
				g.insert(application,computers[x]-'0');
			}
		}while(getline(cin,line) && !line.empty());
		g.allocation();
	}
	return 0;
}