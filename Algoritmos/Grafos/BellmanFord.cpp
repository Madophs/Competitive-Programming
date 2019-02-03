#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
struct vertice{
	vector< pair<vertice*,int> > adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};
class Grafo{
	typedef map<int, vertice*> tabla;
	typedef pair<vertice*, int> vi;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)inserta(x);
	}
	void inserta(int nom){
		vertice *v = new vertice(nom);
		hash.insert(make_pair(nom,v));
	}
	void inAristas(int a, int b, int c){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(vi(iter2->second,c));
		//iter2->second->adj.push_back(vi(iter->second,c));
	}
	int bellman_ford(int inicio, int destino){
		vector<int> dist(noVer, inf);
		dist[inicio]=0;
		for(int x=0; x<noVer-1; x++){
			for(int u=0; u<noVer; u++){
				for(ui v=0; v<hash.find(u)->second->adj.size(); v++){
					tabla::iterator iter = hash.find(u);
					dist[iter->second->adj[v].first->nombre]=min(dist[iter->second->adj[v].first->nombre], dist[u]+iter->second->adj[v].second);
				}
			}
		}
		bool negativo=false;
		for(int u=0; u<noVer; u++){
			for(ui v=0; v<hash.find(u)->second->adj.size(); v++){
				tabla::iterator iter = hash.find(u);
				if(dist[iter->second->adj[v].first->nombre]>dist[u]+iter->second->adj[v].second)negativo=true;
			}
		}
		cout<<(negativo?"SI hay un ciclo negativo\n":"No hay un ciclo negativo\n");
		return dist[destino];
	}
private:
	int noVer;
};
int main(){
	int v;
	cout<<"Bellman Ford's Algortithm"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Inserta aristas"<<endl;
	int a,b,c;
	Grafo g(v);
	while(cin>>a>>b>>c && a>=0 && b>=0)g.inAristas(a,b,c);
	cout<<"Ruta mas corta (inicio, destino)\n";
	while(cin>>a>>b && a>=0 && b>=0){
		cout<<g.bellman_ford(a,b)<<endl;
	}
	return 0;
}
