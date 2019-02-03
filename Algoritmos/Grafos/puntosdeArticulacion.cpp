#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int > ii;
struct vertice{
	vector<vertice*> adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};
class Grafo{
	typedef map< int, vertice*> tabla;
	enum Estado{NoVisitado,Visitado};
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)inserta(x);
	}
	void inArista(int a, int b){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(iter2->second);
		iter2->second->adj.push_back(iter->second);
	}
	void imprimirPuntosAristasDeArticulacion(){
		aristas.clear();
		verticesArticulacion.assign(noVer,0);
		dfs_low.assign(noVer,0);
		dfs_num.assign(noVer,0);
		estado.assign(noVer,NoVisitado);
		contArticulaciones=0;
		hijos=0;
		padre.assign(noVer,0);

		for(int x=0; x<noVer; x++){
			if(estado[x]==NoVisitado){
				raiz=x;
				hijos=0;
				metPuntosAristasDeArticulacion(x);
				verticesArticulacion[raiz]=(hijos>1);
			}
		}
		cout<<"Aristas"<<endl;
		for(int x=0; x<aristas.size(); x++){
			cout<<aristas[x].first<<" "<<aristas[x].second<<"\n";
		}
		cout<<endl;
		cout<<"Puntos de articulacion"<<endl;
		for(int x=0; x<verticesArticulacion.size(); x++){
			if(verticesArticulacion[x])cout<<x<<" ";
		}
		cout<<endl;
	}
	void metPuntosAristasDeArticulacion(int ver){
		dfs_low[ver]=dfs_num[ver]=contArticulaciones++;
		estado[ver]=Visitado;
		tabla::iterator iter = hash.find(ver);
		for(int x=0; x<iter->second->adj.size(); x++){
			if(estado[iter->second->adj[x]->nombre]==NoVisitado){
				padre[iter->second->adj[x]->nombre]=ver;
				if(ver==raiz)hijos++;
				metPuntosAristasDeArticulacion(iter->second->adj[x]->nombre);
				if(dfs_low[iter->second->adj[x]->nombre]>=dfs_num[ver])verticesArticulacion[ver]=1;
				if(dfs_low[iter->second->adj[x]->nombre]>dfs_num[ver])aristas.push_back(make_pair(ver,iter->second->adj[x]->nombre));
				dfs_low[ver]=min(dfs_low[ver], dfs_low[iter->second->adj[x]->nombre]);
			}else if(iter->second->adj[x]->nombre!=padre[ver]){
				dfs_low[ver]=min(dfs_low[ver], dfs_low[iter->second->adj[x]->nombre]);
			}
		}
	}
private:
	vector<ii> aristas;
	int noVer,contArticulaciones,hijos,raiz;
	vector<int> verticesArticulacion,dfs_low,dfs_num,padre;
	vector<Estado> estado;
	void inserta(int ver){
		vertice *v = new vertice(ver);
		hash.insert(make_pair(ver,v));
	}
};
int main(){
	int ver;
	cout<<"Numero de vertices"<<endl;
	cin>>ver;
	Grafo g(ver);
	cout<<"Insersar aristas"<<endl;
	int a,b;
	while(cin>>a>>b && a>=0 && b>=0)g.inArista(a,b);
	g.imprimirPuntosAristasDeArticulacion();
	return 0;
}