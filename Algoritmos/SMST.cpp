#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;

class Union{
public:
	Union(int ver){
		this->noVer=ver;
		rango.assign(noVer,0);
		for(int x=0; x<noVer; x++)padre.push_back(x);
	}
	int find(int ver){
		if(ver==padre[ver]){
			return ver;
		}else{
			ver=find(padre[ver]);
		}
		return ver;
	}
	bool sameSet(int a,int b){
		int x=find(a),y=find(b);
		if(padre[x]==padre[y])return true;
		return false;
	}
	void setUnion(int a, int b){
		if(!sameSet(a,b)){
			int x=find(a),y=find(b);
			if(rango[x]>rango[y]){
				padre[y]=x;
			}else{
				padre[x]=y;
			}
			if(rango[x]==rango[y])++rango[y];
		}
	}
	void resetear(){
		for(int x=0; x<noVer; x++){
			padre[x]=x;
			rango[x]=0;
		}
	}
private:
	int noVer;
	vector<int> padre,rango;
};
int main(){
	int v,e;
	cout<<"Second Minimun Spanning Tree"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Numero de aristas"<<endl;
	do{
		cin>>e;
	}while(e<=v-1);
	cout<<"Ingrese "<<e<<" aristas (v1 v2 peso)"<<endl;
	vector<iii> aristas;
	int a,b,c;
	for(int x=0; x<e; x++){
		cin>>a>>b>>c;
		aristas.push_back(make_pair(c ,make_pair(a,b)));
	}
	sort(aristas.begin(), aristas.end());
	int costo=0,subcosto=1e9,costoMax=0,minMax=0,maxMin=1e9;
	Union u(v);
	vector<ii> subgraph,maxTree;
	for(ui x=0; x<aristas.size();x++){
		if(!u.sameSet(aristas[x].second.first,aristas[x].second.second)){
			costo+=aristas[x].first;
			if(minMax<aristas[x].first)minMax=aristas[x].first;
			subgraph.push_back(ii(aristas[x].second.first,aristas[x].second.second));
			u.setUnion(aristas[x].second.first,aristas[x].second.second);
		}
	}
	u.resetear();
	for(int x=aristas.size()-1; x>=0;x--){
		if(!u.sameSet(aristas[x].second.first,aristas[x].second.second)){
			costoMax+=aristas[x].first;
			if(aristas[x].first<maxMin)maxMin=aristas[x].first;
			maxTree.push_back(ii(aristas[x].second.first,aristas[x].second.second));
			u.setUnion(aristas[x].second.first,aristas[x].second.second);
		}
	}
	int ciclos=v-2,desc=0;
	vector<ii> second;
	while(ciclos--){
		int aux=0,ar=0;
		u.resetear();
		vector<ii> vAux;
		for(ui x=0; x<aristas.size();x++){
			if(x==(ui)desc)continue;
			if(!u.sameSet(aristas[x].second.first,aristas[x].second.second)){
				++ar;
				aux+=aristas[x].first;
				vAux.push_back(ii(aristas[x].second.first,aristas[x].second.second));
				u.setUnion(aristas[x].second.first,aristas[x].second.second);
			}
		}
		if(subcosto>aux && (v-ar)==1){
			subcosto=aux;
			second.assign(vAux.begin(),vAux.end());
		}
		++desc;
	}
	cout<<"Maximun ST vertices"<<endl;
	for(ui x=0; x<maxTree.size(); x++){
		cout<<maxTree[x].first<<" "<<maxTree[x].second<<endl;
	}
	cout<<"MST vertices"<<endl;
	for(ui x=0; x<subgraph.size(); x++){
		cout<<subgraph[x].first<<" "<<subgraph[x].second<<endl;
	}
	cout<<"Second MST vertices"<<endl;
	for(ui x=0; x<second.size(); x++){
		cout<<second[x].first<<" "<<second[x].second<<endl;
	}
	cout<<"Maximun Spanning Tree cost "<<costoMax<<endl;
	cout<<"Minimun Spanning Tree cost "<<costo<<endl;
	cout<<"Second Minimun Spannig Tree cost "<<subcosto<<endl;
	cout<<"MinMax "<<minMax<<endl;
	cout<<"MaxMin "<<maxMin<<endl;
	return 0;
}
