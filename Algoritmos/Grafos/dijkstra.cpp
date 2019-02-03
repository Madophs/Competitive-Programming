#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;

struct vertice{
	vector< pair<vertice*, int> > adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};


class Grafo{
	typedef map< int, vertice*> tabla;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)inserta(x);
	}
	void inserta(int ver){
		vertice *v = new vertice(ver);
		hash.insert(make_pair(ver,v));
	}
	void inAristas(int a, int b, int dist){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(make_pair(iter2->second,dist));
		iter2->second->adj.push_back(make_pair(iter->second,dist));
	}
	void impCamino(vector<int> &camino,int inicio, int destino){
		if(camino[inicio]==-1){
			cout<<inicio<<" ";
			return;
		}
		impCamino(camino,camino[inicio],destino);
		cout<<inicio<<" ";
	}
	int dijkstra(int inicio, int destino){
		dist.assign(noVer,inf);
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0,inicio));
		dist[inicio]=0;
		vector<int> camino(noVer,-1);
		while(!pq.empty()){
			int d=pq.top().first,u=pq.top().second;
			pq.pop();
			if(d>dist[u])continue;
			tabla::iterator iter = hash.find(u);
			for(int x=0; x<iter->second->adj.size(); x++){
				if(dist[u]+iter->second->adj[x].second<dist[iter->second->adj[x].first->nombre]){
					dist[iter->second->adj[x].first->nombre]=dist[u]+iter->second->adj[x].second;
					camino[iter->second->adj[x].first->nombre]=u;
					pq.push(ii(dist[iter->second->adj[x].first->nombre],iter->second->adj[x].first->nombre));
				}
			}
		}
		impCamino(camino,destino,inicio);
		cout<<endl;
		return dist[destino];
	}
private:
	int noVer;
	vector<int> dist;
};
int main(){
	int v,e;
	cout<<"Dijkstra"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Inserte aristas y su peso"<<endl;
	int a,b,c;
	Grafo g(v);
	while(cin>>a>>b>>c && a>=0 && b>=0 && c>=0)g.inAristas(a,b,c);
	cout<<"Inicio destino"<<endl;
	while(cin>>a>>b && a>=0 && b>=0){
		cout<<"Ruta minima "<<g.dijkstra(a,b)<<endl;
	}
	return 0;
}
