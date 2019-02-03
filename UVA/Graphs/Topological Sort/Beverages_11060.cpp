#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<Node*> adj;
	string beverage;
	int incomingDegree, position = 0;
	Node(string name,int position):beverage(name),incomingDegree(0),position(position){}
};

struct Comparator{
	bool operator()(Node *&a, Node *&b){
		return a->position > b->position;
	}
};

class Graph{
public:
	void createNode(string name){
		nodes[name] = new Node(name,nodes.size());
	}
	void connectNodes(string from, string to){
		nodes.find(from)->second->adj.push_back(nodes.find(to)->second);
		++nodes.find(to)->second->incomingDegree;
	}
	vector<string> kahn(){
		priority_queue<Node*, vector<Node*>,Comparator>q;
		vector<string> order;
		for(auto it = nodes.begin(); it!=nodes.end(); it++){
			if(it->second->incomingDegree==0)
				q.push(it->second);
		}
		while(!q.empty()){
			auto node = q.top();
			q.pop();
			order.push_back(node->beverage);
			for(auto it = node->adj.begin(); it!=node->adj.end(); it++){
				auto ref = *it;
				--ref->incomingDegree;
				if(ref->incomingDegree == 0)q.push(ref);
			}
		}
		return order;
	}
private:
	unordered_map<string,Node*> nodes;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,e,noCase = 0;
	string beverage, lower,upper;
	while(cin>>n){
		Graph g;
		while(n-- && cin>>beverage) g.createNode(beverage);
		cin>>e;
		while(e-- && cin>>lower>>upper) g.connectNodes(lower,upper);
		vector<string> order = g.kahn();
		cout<<"Case #"<<++noCase<<": Dilbert should drink beverages in this order:";
		for(auto it = order.begin(); it!=order.end(); it++) cout<<" "<<*it;
		cout<<".\n\n";
	}
	return 0;
}