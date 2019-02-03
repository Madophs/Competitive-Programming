#include <bits/stdc++.h>

using namespace std;

struct Vertex{
	vector<Vertex*> adj;
	int nom;
	bool blocked;
	Vertex(int name=0):nom(name),blocked(false){}
};

class Graph{
public:
	unordered_map<int,Vertex*> mapa;
	Graph(int tam){
		this->underscores.assign((tam*2)-1,'-');
		for(int x=0; x<tam; x++)mapa[x]= new Vertex(x);
	}
	void addEdge(int from, int to){
		auto temp = mapa.find(from);
		auto temp2 = mapa.find(to);
		temp->second->adj.push_back(temp2->second);
	}
	void dominator(){
		bool rootEmpty = mapa.find(0)->second->adj.empty();
		bitset<101> auxRoot;
		cout<<"+"<<underscores<<"+\n";
		for(int x=0; x<mapa.size(); x++){
			visited.reset();
			auto aux =mapa.find(x)->second;
			aux->blocked=true;
			dfs(0);
			aux->blocked=false;
			for(int x=0; x<mapa.size(); x++){
				cout<<"|";
				if(!auxRoot[x] && aux->nom!=0){
					cout<<"N";
				}else if(aux->nom==0 && x==0){
					cout<<"Y";
				}else if(visited[x] && aux->nom==0){
					cout<<"Y";
				}else if(visited[x] || rootEmpty){
					cout<<"N";
				}else if(!visited[x] && aux->nom==0){
					cout<<"N";
				}else{
					cout<<"Y";
				}
			}
			if(aux->nom==0){
				auxRoot=visited;
			}
			cout<<"|\n";
			cout<<"+"<<underscores<<"+\n";
		}
	}
	void dfs(int v){
		auto current = mapa.find(v)->second;
		visited[v]=true;
		for(auto iter = current->adj.begin(); iter!=current->adj.end(); iter++){
			auto ref = *iter;
			if(!visited[ref->nom] && !ref->blocked){
				dfs(ref->nom);
			}
		}
	}
private:
	bitset<101> visited;
	string underscores;
};
int main(){
	ios::sync_with_stdio(false);
	int t,nodes,var,c=0;cin>>t;
	while(t--){
		cin>>nodes;
		Graph g(nodes);
		for(int x=0; x<nodes; x++){
			for(int y=0; y<nodes; y++){
				cin>>var;
				if(var && x!=y)g.addEdge(x,y);
			}
		}
		cout<<"Case "<<++c<<":\n";
		g.dominator();
	}
	return 0;
}
