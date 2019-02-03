#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector< pair<int,Node*> > adj;
	int name;
	Node(int name):name(name){}
};

class Graph{
	public:
		Graph(int size){
			visited.assign(size+1,false);
			for(int x=0; x<size; x++) nodesTable[x] = new Node(x);
			total = 0;
		}

		void connectNodes(int from, int to, int weight){
			auto itFrom = nodesTable.find(from);
			auto itTo = nodesTable.find(to);
			itFrom->second->adj.push_back(make_pair(weight,itTo->second));
			itTo->second->adj.push_back(make_pair(weight,itFrom->second));
			total+=weight;
		}

		int savedMoney(){
			priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > edges;
			primProcess(0,edges);
			int minCost = 0;
			while(!edges.empty()){
				pair<int,int> values = edges.top();
				edges.pop();
				if(!visited[values.second]){
					minCost+=values.first;
					primProcess(values.second,edges);
				}
			}
			return total-minCost;
		}

		void primProcess(int node, priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > &q){
			visited[node] = true;
			auto adj = nodesTable.find(node)->second->adj;
			for(auto it = adj.begin(); it!=adj.end(); it++){
				if(!visited[it->second->name]) q.push(make_pair(it->first, it->second->name));
			}
		}
	private:
		vector<bool> visited;
		unordered_map<int,Node*> nodesTable;
		int total;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int juntions, roads,a,b, weight;
	while(cin>>juntions>>roads && (juntions || roads)){
		Graph g(juntions);
		while(roads-- && cin>>a>>b>>weight) g.connectNodes(a,b,weight);
		cout<<g.savedMoney()<<'\n';
	}
	return 0;
}