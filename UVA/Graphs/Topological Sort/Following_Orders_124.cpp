#include <bits/stdc++.h>

using namespace std;

struct Node{
	int inDegree, outDegree;
	char name;
	bool inUse;
	set<char> adj;
	Node(char name){
		this->inDegree = 0;
		this->outDegree = 0;
		this->name = name;
		this->inUse = false;
	}
};

class Graph{
	public:
		Graph(string lineNodes){
			for(char i = 'a'; i <= '{'; i++){
				nodes.emplace_back(Node(i));
			}
			stringstream ss(lineNodes);
			char nodeName;
			while(ss>>nodeName)
				nodes[nodeName-'a'].inUse = true, inUseArray.emplace_back(nodeName);
		}
		void connectNodes(char a, char b){
			if(a == b) return;
			nodes[a-'a'].adj.insert(b);
			++nodes[a-'a'].outDegree;
			++nodes[b-'a'].inDegree;
		}
		void connectGraph(){
			for(int i = 0; i<nodes.size(); i++){
				if(nodes[i].inUse && !nodes[i].inDegree && nodes[i].outDegree){
					connectNodes(nodes.back().name, nodes[i].name);
				}
			}
		}
		void generateAllOrderings(char u,string solution = ""){
			visited.set((int)u);
			if(u != '{') solution +=  u;
			auto adj = nodes[u-'a'].adj;
			for(auto v = adj.begin(); v != adj.end(); v++) --nodes[*v-'a'].inDegree;
			for(auto v = nodes.begin(); v != nodes.end(); v++){
				if(!nodes[v->name-'a'].inUse) continue;
				if(!visited.test((int)v->name) && nodes[v->name-'a'].inDegree <= 0){
					generateAllOrderings(v->name, solution);
					visited.reset((int)v->name);
				}
			}
			for(auto v = adj.begin(); v != adj.end(); v++) ++nodes[*v-'a'].inDegree;
			if(solution.length() == inUseArray.size())
				cout<<solution<<"\n";
		}
	private:
		vector<Node> nodes;
		vector<char> inUseArray;
		bitset<300> visited;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string lineNodes, lineConditions;
	char a, b;
	int blackLine = 0;
	while(getline(cin, lineNodes)){
		getline(cin, lineConditions);
		Graph g(lineNodes);
		stringstream ss(lineConditions);
		while(ss>>a>>b) g.connectNodes(a,b);
		g.connectGraph();
		if(blackLine++) cout<<"\n";
		g.generateAllOrderings('{');
	}	
	return 0;
}
