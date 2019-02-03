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
	void inArista(int a, int b,int c){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(iter2->second);
		if(c==2)iter2->second->adj.push_back(iter->second);
	}
	bool tarjanAlgoritmo(){
		dfs_low.assign(noVer,0);
		dfs_num.assign(noVer,0);
		estado.assign(noVer,NoVisitado);
		cont=0;
		numSCC=0;
		for(int x=0; x<noVer; x++){
			if(estado[x]==NoVisitado){
				tarjanSCC(x);
			}
		}
		return numSCC==1 && sets==noVer;
	}
	void tarjanSCC(int ver){
		dfs_low[ver]=dfs_num[ver]=cont++;
		estado[ver]=Visitado;
		pila.push(ver);
		tabla::iterator iter = hash.find(ver);
		for(int x=0; x<iter->second->adj.size(); x++){
			if(estado[iter->second->adj[x]->nombre]==NoVisitado){
				tarjanSCC(iter->second->adj[x]->nombre);
			}
			if(estado[iter->second->adj[x]->nombre]==Visitado){
				dfs_low[ver]=min(dfs_low[ver], dfs_low[iter->second->adj[x]->nombre]);
			}
		}
		if(dfs_low[ver]==dfs_num[ver]){
			++numSCC;
			sets=pila.size();
			while(true){
				int v=pila.top();
				pila.pop();
				if(ver==v)break;
			}
		}
	}
private:
	int noVer,cont,raiz,numSCC,sets;
	vector<int> dfs_low,dfs_num;
	vector<Estado> estado;
	stack<int> pila;
	void inserta(int ver){
		vertice *v = new vertice(ver);
		hash.insert(make_pair(ver,v));
	}
};
int main(){
	int n,m;
	ios_base::sync_with_stdio(false);
	while(cin>>n>>m && (n || m)){
		int a,b,c;
		Grafo g(n);
		while(m--){
			cin>>a>>b>>c;
			--a;--b;
			g.inArista(a,b,c);
		}
		cout<<g.tarjanAlgoritmo()<<endl;
	}
	return 0;
}
