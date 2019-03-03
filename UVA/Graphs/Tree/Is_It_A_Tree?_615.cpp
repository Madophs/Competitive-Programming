#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<Node*> adj;
	int data;
	bool root,visited;
	Node(int data):data(data),root(true),visited(false){}
};

class Tree{
	public:
		unordered_map<int, Node*> nodes;
		int visitedNodes;
		Tree(){
			this->visitedNodes = 0;
		}
		void connectNodes(int a, int b){
			if(nodes.find(a) == nodes.end()) nodes[a] = new Node(a);
			if(nodes.find(b) == nodes.end()) nodes[b] = new Node(b);
			nodes.find(a)->second->adj.push_back(nodes.find(b)->second);
			nodes.find(b)->second->root = false;
		}
		int findRoot(){
			for(auto node = nodes.begin(); node!=nodes.end(); node++){
				if(node->second->root) return node->second->data;
			}
			return -1;
		}
		bool isItATree(){
			int root = findRoot();
			if(root == -1) return false;
			bool isTree = dfs(root);
			if(nodes.size()!=visitedNodes) return false;
			return isTree;
		}
		bool dfs(int parent){
			auto tempNode = nodes.find(parent)->second;
			tempNode->visited = true;
			bool ret = true;
			++visitedNodes;
			for(auto it = tempNode->adj.begin(); it!=tempNode->adj.end(); it++){
				auto ref = *it;
				if(ref->visited){
					return false;
				}else{
					ret = dfs(ref->data);
				}
			}
			return ret;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, testNum = 0;
	while(cin>>a>>b && a>=0 && b>=0){
		Tree t;
		if(a && b){
			t.connectNodes(a,b);
		}else{
			t.connectNodes(1,2);
		}
		if(a && b)
			while(cin>>a>>b && (a || b)) t.connectNodes(a,b);
		if(t.isItATree()){
			cout<<"Case "<<++testNum<<" is a tree.\n";
		}else{
			cout<<"Case "<<++testNum<<" is not a tree.\n";
		}
	}
	return 0;
}