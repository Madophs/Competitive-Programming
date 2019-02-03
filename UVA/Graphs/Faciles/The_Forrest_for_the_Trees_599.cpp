#include<bits/stdc++.h>

using namespace std;

struct Vertex{
	vector<Vertex*> adj;
	char name;
	Vertex(char name):name(name){}
};

class Graph{
public:
	unordered_map<char,Vertex*> mapa;
	Graph(){
		memset(nodes,0,sizeof(nodes));
		this->visitado.reset();
	}
	void addEdge(char from, char to){
		if(mapa.find(from)==mapa.end())mapa[from] = new Vertex(from);
		if(mapa.find(to)==mapa.end())mapa[to] = new Vertex(to);
		auto v1 = mapa.find(from);
		auto v2 = mapa.find(to);
		v1->second->adj.push_back(v2->second);
		v2->second->adj.push_back(v1->second);
		++nodes[from-'A'];
		++nodes[to-'A'];
	}
	void addIfNotExist(char name){
		if(nodes[name-'A']==0)mapa[name] = new Vertex(name);
	}
	vector <int> dfs(){
		vector<int> ans(2,0);
		for(auto iter = mapa.begin(); iter!=mapa.end(); iter++){
			auto ref = *iter;
			if(!visitado[ref.first]){
				int res=dfs(ref.first);
				if(res>0){
					++ans[0];
				}else{
					++ans[1];
				}
			}
		}
		return ans;
	}
	int dfs(char v){
		this->visitado[v]=true;
		auto current = mapa.find(v);
		int res=current->second->adj.size();
		for(auto iter = current->second->adj.begin(); iter!=current->second->adj.end(); iter++){
			auto ref = *iter;
			if(!visitado[ref->name]){
				res+=dfs(ref->name);
			}
		}
		return res;
	}
private:
	int nodes[27];
	bitset<30> visitado;
};
int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;
	string edges,nodes,aux;
	while(t--){
		Graph g;
		while(cin>>edges){
			if(edges.at(0)=='*')break;
			g.addEdge(edges.at(1),edges.at(3));
		}
		cin>>nodes;
		istringstream iss(nodes);
		while(getline(iss,aux,',')){
			g.addIfNotExist(aux.at(0));
		}
		vector<int> ans = g.dfs();
		cout<<"There are "<<ans[0]<<" tree(s) and "<<ans[1]<<" acorn(s).\n";
	}
	return 0;
}
