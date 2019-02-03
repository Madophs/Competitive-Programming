#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<Node*> adj;
	string name;
	Node(string name):name(name){}
};

class Graph{
	public:
		void creareNode(string word){
			nodes[word] = new Node(word);
		}
		void connectNodes(){
			for(auto from = nodes.begin(); from!=nodes.end(); from++){
				for(auto to = nodes.begin(); to!=nodes.end(); to++){
					if(to == from || to->first.length()!=from->first.length()) continue;
					int diff = 0;
					for(int x=0; x<from->first.length(); x++){
						if(from->first[x]!=to->first[x]) ++diff;
						if(diff>1)break;
					}
					if(diff==1){
						from->second->adj.push_back(to->second);
						to->second->adj.push_back(from->second);
					}
				}
			}
		}
		int shortestPossibleTransformation(string from, string to){
			unordered_set<string> visited;
			queue< pair<string,int> > order;
			bool found = false;
			order.push(make_pair(from,0));
			visited.insert(from);
			while(!order.empty() && !found){
				pair<string,int> word = order.front();
				order.pop();
				auto adj = nodes.find(word.first)->second->adj;
				for(auto it =  adj.begin(); it!=adj.end(); it++){
					auto ref = *it;
					if(visited.find(ref->name) == visited.end()){
						pair<string,int> distanceNode = make_pair(ref->name,word.second+1);
						if(ref->name == to) return distanceNode.second;
						visited.insert(ref->name);
						order.push(distanceNode);
					}
				} 
			}
			return 0;
		}
	private:
		unordered_map<string, Node*> nodes;

};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,index;
	bool jump = false;
	string word1, word2,line;
	cin>>t;
	cin.ignore();
	while(t--){
		if(jump)cout<<'\n';
		jump = true;
		Graph g;
		while(getline(cin,line) && line!="*"){
			g.creareNode(line);
		}
		g.connectNodes();
		while(getline(cin,line) && !line.empty()){
			stringstream ss(line);
			ss>>word1>>word2;
			cout<<word1<<" "<<word2<<" "<<g.shortestPossibleTransformation(word1,word2)<<"\n";
		}
	}
	return 0;
}