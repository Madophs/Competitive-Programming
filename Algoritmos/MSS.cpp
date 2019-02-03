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
private:
	int noVer;
	vector<int> padre,rango;
};
int main(){
	int v,e;
	cout<<"Minimun Spanning Subgraph"<<endl;
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
	int fijas = e-(v-1);
	int costo=0;
	Union u(v);
	vector<ii> subgraph;
	for(vector<iii>::reverse_iterator iter = aristas.rbegin(); fijas--; iter++){
		costo+=iter->first;
		subgraph.push_back(ii(iter->second.first,iter->second.second));
		u.setUnion(iter->second.first,iter->second.second);
	}
	for(ui x=0; x<aristas.size()-(e-(v-1));x++){
		if(!u.sameSet(aristas[x].second.first,aristas[x].second.second)){
			costo+=aristas[x].first;
			subgraph.push_back(ii(aristas[x].second.first,aristas[x].second.second));
			u.setUnion(aristas[x].second.first,aristas[x].second.second);
		}
	}
	cout<<"Subgrafo"<<endl;
	for(ui x=0; x<subgraph.size(); x++){
		cout<<subgraph[x].first<<" "<<subgraph[x].second<<endl;
	}
	cout<<"Minimun Spannig Subgraph "<<costo<<endl;
	return 0;
}
