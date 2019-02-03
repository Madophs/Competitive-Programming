#include <bits/stdc++.h>
#define unvisited -1

using namespace std;

struct Node{
	vector<Node*> adj;
	int data;
	Node(int val):data(val){}
};

class Graph{
public:
	Graph(int size){
		for(int x=1; x<=size; x++) nodes[x] = new Node(x);
		SCC = 0;
		counter = 0;
		dfs_low.assign(size+2,0);
		dfs_num.assign(size+2,-1);
	}

	void createStreet(int from, int to, int direction){
		if(direction&1){
			auto itFrom = nodes.find(from);
			auto itTo = nodes.find(to);
			itFrom->second->adj.push_back(itTo->second);
		}else{
			auto itFrom = nodes.find(from);
			auto itTo = nodes.find(to);
			itFrom->second->adj.push_back(itTo->second);
			itTo->second->adj.push_back(itFrom->second);
		}
	}

	void tarjanAlgorithm(){
		for(int x=1; x<=nodes.size(); x++){
			if(dfs_num[x] == unvisited){
				tarjanAlgorithm(x);
			}
		}
	}
	void tarjanAlgorithm(int node){
		dfs_num[node] = dfs_low[node] = counter++;
		visited.set(node);
		order.push(node);
		auto adj = nodes.find(node)->second->adj;
		for(auto it = adj.begin(); it!=adj.end(); it++){
			auto ref = *it;
			if(dfs_num[ref->data] == unvisited)tarjanAlgorithm(ref->data);
			if(visited.test(ref->data)){
				dfs_low[node] = min(dfs_low[node],dfs_low[ref->data]);
			}
		}
		if(dfs_num[node] == dfs_low[node]){
			++SCC;
			while(1){
				int v = order.top();
				order.pop();
				visited.reset(v);
				if(v == node)break;
			}
		}
	}
	bool isSCC(){
		return SCC==1;
	}
private:
	unordered_map<int,Node*> nodes;
	stack<int> order;
	vector<int> dfs_num,dfs_low;
	bitset<2002> visited;
	int SCC;
	int counter;
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int intersections, streets, a,b, way;
	while(cin>>intersections>>streets && (intersections || streets)){
		Graph g(intersections);
		while(streets-- && cin>>a>>b>>way)g.createStreet(a,b,way);
		g.tarjanAlgorithm();
		cout<<g.isSCC()<<'\n';
	}
	return 0;
}