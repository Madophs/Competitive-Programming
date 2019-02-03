#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<Node*> adj;
	int value;
	Node(int value):value(value){}
};

class Graph{
public:
	Graph(int size){
		this->size = size;
		for(int x=1; x<=size; x++)table[x] = new Node(x);
	}

	void insertEgde(int from, int to){
		auto pFrom = table.find(from)->second;
		auto pTo = table.find(to)->second;
		pFrom->adj.push_back(pTo);
		pTo->adj.push_back(pFrom);
	}

	int bfs(int level){
		vector<bool> visited(size+1,false);
		vector<int> nodesLevel(size+1,0);
		queue<int> q;
		int count = 0;
		q.push(1);
		visited[1] = true;
		nodesLevel[1] = 1;
		if(nodesLevel[1] == level)++count;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			auto adj = table.find(node)->second;
			for(auto iter = adj->adj.begin(); iter!=adj->adj.end(); iter++){
				auto ref = *iter;
				if(!visited[ref->value]){
					visited[ref->value] = true;
					nodesLevel[ref->value] = nodesLevel[node]+1;
					q.push(ref->value);
					if(nodesLevel[ref->value] == level) ++count;
				}
			}
		}
		return count;
	}
private:
	unordered_map<int,Node*> table;
	int size;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,edges,a,b,level;
	cin>>size;
	Graph g(size);
	for(int x=0; x<size-1 && cin>>a>>b; x++)g.insertEgde(a,b);
	cin>>level;
	cout<<g.bfs(level)<<'\n';
	return 0;
}