#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<char> adj;
	char name;
	int timeNeeded, incommingDegree;
	Node(char name, int timeNeeded){
		this->name = name;
		this->timeNeeded = timeNeeded;
		this->incommingDegree = 0;
	}
};

class Graph{
	public:
		unordered_map<char,Node> nodes;
		void createNewNode(char &name, int timeNeeded){
			if(nodes.find(name) == nodes.end()){
				nodes.insert(make_pair(name,Node(name,timeNeeded)));
			}else{
				nodes.find(name)->second.timeNeeded = timeNeeded;
			}
		}
		void insertNodes(string sentence){
			stringstream ss(sentence);
			char newNode, oldNode;
			int timeNeeded;
			ss>>newNode;
			ss>>timeNeeded;
			timeNeeded *=-1;
			createNewNode(newNode, timeNeeded);
			if(ss.eof()) return;
			string connectedNodes;
			ss>>connectedNodes;
			for(auto i = connectedNodes.begin(); i!=connectedNodes.end(); i++){
				if(nodes.find(*i) == nodes.end()) nodes.insert(make_pair(*i, Node(*i,0)));
				nodes.find(*i)->second.adj.emplace_back(newNode);
				++nodes.find(newNode)->second.incommingDegree;
			}
		}

		int timeNeededToComplete(){
			queue<char> order;
			int ans = (int)1e9;
			int timeNeeded[27];
			memset(timeNeeded,0,sizeof timeNeeded);
			for(auto it = nodes.begin(); it!=nodes.end(); it++){
				if(it->second.incommingDegree == 0){
					order.push(it->first);
					timeNeeded[it->first-'A'] = it->second.timeNeeded;
					ans = min(ans, it->second.timeNeeded);
				}
			}
			while(!order.empty()){
				char currentNode = order.front();
				order.pop();
				auto adj = nodes.find(currentNode)->second.adj;
				int currentTimeForTask = timeNeeded[currentNode-'A'];
				for(int i = 0; i<adj.size(); i++){
					int timeForTask = nodes.find(adj[i])->second.timeNeeded;
					if(currentTimeForTask + timeForTask < timeNeeded[adj[i]-'A']){
						timeNeeded[adj[i]-'A'] = currentTimeForTask + timeForTask;
						ans = min(ans, timeNeeded[adj[i]-'A']);
						order.push(adj[i]);
					}
				}
			}
			return ans*-1;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string line;
	cin>>tests;
	cin.ignore();
	cin.ignore();
	for(int t = 0; tests--; t++){
		if(t) cout<<"\n";
		Graph g;
		while(getline(cin,line) && !line.empty()){
			g.insertNodes(line);
		}
		cout<<g.timeNeededToComplete()<<"\n";
	}
	return 0;
}