#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;

class Union{
public:
	Union(int tam):noVer(tam){
		rango.assign(noVer,0);
		for(int x=0; x<noVer; x++)padre.push_back(x);
	}
	int encuentra(int ver){
		if(ver==padre[ver]){
			return ver;
		}else{
			ver=encuentra(padre[ver]);
		}
		return ver;
	}
	bool sonConjunto(int a, int b){
		int ver1=encuentra(a);
		int ver2=encuentra(b);
		if(ver1==ver2)return true;
		return false;
	}
	void unir(int a, int b){
		if(!sonConjunto(a,b)){
			int x=encuentra(a), y=encuentra(b);
			if(rango[x]>rango[y]){
				padre[y]=x;
			}else{
				padre[x]=y;
			}
			if(rango[x]==rango[y])++rango[y];
		}
	}
private:
	int noVer;
	vector<int> padre,rango;
};
int main(){
	int v,e;
	cout<<"Algoritmo de Kruskal"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Numero de aristas (aristas>="<<(v-1)<<")"<<endl;
	do{
		cin>>e;
	}while(e<v-1);
	vector<iii> aristas;
	int peso,v1,v2;
	cout<<"Inserte la aristas (vertice 1, vertice 2,peso)"<<endl;
	for(int x=0; x<e; x++){
		cin>>v1>>v2>>peso;
		aristas.push_back(make_pair(peso,make_pair(v1,v2)));
	}
	sort(aristas.begin(),aristas.end());
	Union u(v);
	int costMin=0;
	for(ui x=0; x<aristas.size(); x++){
		if(!u.sonConjunto(aristas[x].second.first,aristas[x].second.second)){
			costMin+=aristas[x].first;
			cout<<aristas[x].second.first<<" - "<<aristas[x].second.second<<endl;
			u.unir(aristas[x].second.first,aristas[x].second.second);
		}
	}
	cout<<"El costo minimo es: "<<costMin<<endl;
	return 0;
}
