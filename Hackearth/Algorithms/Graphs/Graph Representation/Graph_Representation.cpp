#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<Node*> adj;
	int value;
	Node(int value):value(value){}
};

class Graph{
public:
	void insertEdge(int from, int to){
		if(table.find(from) == table.end()) table[from] = new Node(from);
		if(table.find(to) == table.end()) table[to] = new Node(to);
		table.find(from)->second->adj.push_back(table.find(to)->second);
		table.find(to)->second->adj.push_back(table.find(from)->second);
	}
	string thereIsAnEdge(int from, int to){
		bool exists = false;
		auto adj = table.find(from)->second->adj;
		for(auto iter = adj.begin(); iter!=adj.end(); iter++){
			auto ref = *iter;
			if(ref->value == to){
				exists = true;
				break;
			}
		}
		return exists?"YES":"NO";
	}
private:
	unordered_map<int,Node*> table;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes,edges,a,b,q;
	Graph g;
	cin>>nodes>>edges;
	while(edges-- && cin>>a>>b)g.insertEdge(a,b);
	cin>>q;
	while(q-- && cin>>a>>b)cout<<g.thereIsAnEdge(a,b)<<'\n';
	return 0;
}