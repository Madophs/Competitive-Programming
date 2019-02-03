#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int>ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<string, int> si;
typedef pair< int, vector<int> > ivi;
typedef pair< int, vector<ii> > ivii;
typedef unordered_multimap<string, vector<si> > ms;
typedef unsigned int ui;

class Grafo{
	typedef unordered_map<int,vector<ii>> tabla;
	const int rango = 100;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		int cap;
		for(int x=0; x<noVer; x++){
			cout<<"Ingresa la capacidad del vertice "<<x<<endl;
			cin>>cap;
			capacidad(x,cap);
		}
	}
	void capacidad(int nom, int capacidad){
		int aux = nom+rango;
		vii nuevo,split;
		split.push_back(make_pair(nom,capacidad));
		nuevo.push_back(make_pair(aux,capacidad));
		hash.insert(make_pair(nom,nuevo));
		hash.insert(make_pair(aux,split));
	}
	void inArista(int a, int b, int capacidad){
		a+=rango;
		auto p = hash.find(a);
		auto p2 = hash.find(b);
		p->second.push_back(make_pair(b,capacidad));
		p2->second.push_back(make_pair(a,capacidad));
	}
	void aumento(int inicio, int actual, int minimo){
		if(inicio==actual){
			f=minimo;
			return;
		}else if (padre[actual]!=-1){
			auto iter = hash.find( (int)padre[actual]);
			int x=0,val=0;
			for(; x<iter->second.size(); x++){
				if(iter->second[x].first==actual){
					val=iter->second[x].second;
					break;
				}
			}
			aumento(inicio,padre[actual],min(minimo,val));
			actualiza(padre[actual],actual,f);
		}
	}
	int edmonds_karp(int inicio, int final){
		inicio+=rango;
		final+=rango;
		int mf=0;
		while(true){
			f=0;
			bitset<100000> vis;
			padre.assign(100000,-1);
			vis[inicio]=true;
			queue<int> q;
			q.push(inicio);
			while(!q.empty()){
				int u = q.front();q.pop();
				if(u==final)break;
				for(auto x = hash.find(u)->second.begin(); x!=hash.find(u)->second.end(); x++){
					ii par = *x;
					if(!vis[par.first] && par.second>0){
						vis[par.first]=true;
						q.push(par.first);
						padre[par.first]=u;
					}
				}
			}
			aumento(inicio,final,inf);
			if(f==0)return mf;
			mf+=f;
		}

	}
	void actualiza(int padre,int actual,int &val){
		auto p = hash.find(padre);
		auto p2 = hash.find(actual);
		for(ui x=0; x<p->second.size(); x++){
			if(p->second[x].first==actual){
				p->second[x].second-=val;
				break;
			}
		}
		for(ui x=0; x<p2->second.size(); x++){
			if(p2->second[x].first==padre){
				p2->second[x].second+=val;
				break;
			}
		}
	}
	void bfs(){
		bitset<100000> vis,imp;
		vector<int> dist(10000,0);
		vis[0]=true;
		dist[0]=0;
		queue<int> q;
		q.push(0);
		int salto =0;
		cout<<"Longitud de salto "<<salto<<": ";
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u<rango){
				cout<<u<<"_in ";
			}else{
				cout<<(u-rango)<<"_out ";
			}
			for(auto x = hash.find(u)->second.begin(); x!=hash.find(u)->second.end(); x++){
				ii par = *x;
				if(!vis[par.first]){
					vis[par.first]=true;
					dist[par.first]=dist[u]+1;
					q.push(par.first);
				}
			}
			int val =!q.empty()?q.front():u;
			if(dist[val]>salto ){
				cout<<"\nLongitud de salto "<<++salto<<": ";
			}
		}
		cout<<endl;
	}
private:
	int noVer,f;
	vi padre;
};
int main(){
	int v;
	cout<<"Algoritmo de Edmonds Karp con capacidades en los vertices"<<endl;
	cout<<"Ingresa el numero de vertices"<<endl;
	cin>>v;
	Grafo g(v);
	cout<<"Ingresa la aristas (v1 v1 peso)"<<endl;
	int a,b,c;
	while(cin>>a>>b>>c && a>=0 && b>=0 && c>=0)g.inArista(a,b,c);
	cout<<"Calcular el flujo maximo de v1 a v2"<<endl;
	g.bfs();
	cin>>a>>b;
	cout<<g.edmonds_karp(a,b)<<endl;
	return 0;
}
/*
5
999
5
30
5
2
0 1 20
1 2 5
1 4 7
4 2 3
3 2 7
0 3 10
-1 -1 -1
 *
 */
