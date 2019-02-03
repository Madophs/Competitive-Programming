#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;

struct vertice{
	vector< pair< vertice* , int> > adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};

class Grafo{
	enum Estado{NoVisitado, Visitado};
	typedef map< int, vertice*> tabla;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		for(int x=0;x<noVer; x++)inserta(x);
	}
	void inAristas(int a, int b,  int c){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(make_pair(iter2->second,c));
		iter2->second->adj.push_back(make_pair(iter->second,c));
	}
	int pirm(){
		estado.assign(noVer,NoVisitado);
		int costMin=0;
		proceso(0);
		while(!pq.empty()){
			int ver=pq.top().second;
			int peso=pq.top().first;
			pq.pop();
			if(estado[ver]==NoVisitado){
				costMin+=peso, proceso(ver);
			}
		}
		return costMin;
	}
private:
	int noVer;
	vector<Estado> estado;
	priority_queue< ii ,vector< ii >, greater<ii> > pq;
	void inserta(int nom){
		vertice *v = new vertice(nom);
		hash.insert(make_pair(nom,v));
	}
	void proceso(int ver){
		estado[ver]=Visitado;
		tabla::iterator iter = hash.find(ver);
		for(ui x=0; x<iter->second->adj.size(); x++){
			if(estado[iter->second->adj[x].first->nombre]==NoVisitado)pq.push(ii(iter->second->adj[x].second,iter->second->adj[x].first->nombre));
		}
	}
};
int main(){
	int v,e;
	cout<<"Algoritmo de prim"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Numero de aristas (aristas>="<<(v-1)<<")"<<endl;
	do{
		cin>>e;
	}while(e<v-1);
	Grafo g(v);
	int a,b,c;
	cout<<"Inserte aristas v1 v2 peso"<<endl;
	for(int x=0; x<e; x++){
		cin>>a>>b>>c;
		g.inAristas(a,b,c);
	}
	cout<<"Costo minimo: "<<g.pirm()<<endl;
	return 0;
}
