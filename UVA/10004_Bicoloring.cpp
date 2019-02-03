#include <bits/stdc++.h>

using namespace std;
struct vertice{
	vector<vertice*> adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};

class Graph{
public:
	map<int, vertice*> hash;
	Graph(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)insertar(x);
	}
	void insertar(int val){
		vertice *v = new vertice(val);
		hash.insert(make_pair(val,v));
	}
	void inArcos(int a, int b){
		map<int, vertice*>::iterator iter= hash.find(a);
		map<int, vertice*>::iterator iter2= hash.find(b);
		iter->second->adj.push_back(iter2->second);
		iter2->second->adj.push_back(iter->second);
	}
	bool bipartite(){
		queue<int> cola;
		vector<int> color(noVer+1,1e9);
		color[0]=0;
		cola.push(0);
		while(!cola.empty()){
			int u=cola.front();
			cola.pop();
			map<int, vertice*>::iterator iter = hash.find(u);
			for(int x=0; x<iter->second->adj.size(); x++){
				if(color[iter->second->adj[x]->nombre]==1e9){
					color[iter->second->adj[x]->nombre]=1-color[u];
					cola.push(iter->second->adj[x]->nombre);
				}else if(color[iter->second->adj[x]->nombre]==color[u]){
					return false;
					break;
				}
			}
		}
		return true;
	}
private:
	int noVer;
};
int main(){
	ios_base::sync_with_stdio(false);
	int nodes,edges;
	while(cin>>nodes && nodes){
		Graph g(nodes);
		cin>>edges;
		int a,b;
		while(edges--){
			cin>>a>>b;
			g.inArcos(a,b);
		}
		cout<<(g.bipartite()?"BICOLORABLE.":"NOT BICOLORABLE.")<<endl;
	}
}
