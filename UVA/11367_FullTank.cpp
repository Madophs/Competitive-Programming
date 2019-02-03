#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int>ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef unsigned int ui;
struct vertice{
	vector <pair<vertice*,int> > adj;
	int nombre,precio;
	vertice(int nom,int precio):nombre(nom),precio(precio){}
};
int estado[1000][101];
class Grafo{
	int noVer=0;
	typedef pair<vertice*,int> veri;
	typedef unordered_map<int, vertice*> tabla;
public:
	tabla hash;
	void inserta(int nom, int precio){
		vertice *v = new vertice(nom,precio);
		hash.insert(make_pair(nom,v));
		++noVer;
	}
	void inAristas(int a, int b, int dist){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(veri(iter2->second,dist));
		iter2->second->adj.push_back(veri(iter->second,dist));
	}
	int dijkstra(const int capacidad, int inicio, int destino){
		for(int x=0;x<noVer; x++){
			for(int y=0; y<=capacidad; y++){
				estado[x][y]=inf;
			}
		}
		priority_queue<iii,vector<iii>, greater<iii> > pq;
		pq.push(iii(0,ii(0,inicio)));
		estado[inicio][0]=0;
		while(!pq.empty()){
			iii info = pq.top();
			pq.pop();
			if(info.second.second==destino){
				return info.first;
			}
			if(info.first>estado[info.second.second][info.second.first])continue;
			tabla::iterator iter = hash.find(info.second.second);
			if(info.second.first<capacidad && info.first+iter->second->precio<estado[info.second.second][info.second.first+1]){
				estado[info.second.second][info.second.first+1]=info.first+iter->second->precio;
				pq.push(iii(estado[info.second.second][info.second.first+1],ii(info.second.first+1,info.second.second)));
			}
			for(int x=0; x<iter->second->adj.size(); x++){
				if(info.second.first>=iter->second->adj[x].second){
					int gasolina=info.second.first-iter->second->adj[x].second;
					if(info.first<estado[iter->second->adj[x].first->nombre][gasolina]){
						estado[iter->second->adj[x].first->nombre][gasolina]=info.first;
						pq.push(iii(info.first,ii(gasolina,iter->second->adj[x].first->nombre)));
					}
				}
			}
		}
		return inf;
	}
private:
};
int main(){
	string cadena;
	while(getline(cin,cadena) && !cadena.empty()){
		int v,e,p;
		stringstream tk(cadena);
		tk>>v;
		tk>>e;
		Grafo g;
		for(int x=0; x<v; x++){
			cin>>p;
			g.inserta(x,p);
		}
		int a,b,c;
		while(e--){
			cin>>a>>b>>c;
			g.inAristas(a,b,c);
		}
		cin>>e;
		int cap,inicio,final;
		while(e--){
			cin>>cap>>inicio>>final;
			int res=g.dijkstra(cap,inicio,final);
			if(res==inf){
				cout<<"impossible\n";
			}else{
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}
