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
	int v,e,k;
	cout<<"Minimun Spanning Forest"<<endl;
	cout<<"Numero de vertices"<<endl;
	cin>>v;
	cout<<"Numero de aristas"<<endl;
	do{
		cin>>e;
	}while(e<=v-1);
	cout<<"Numero de arboles"<<endl;
	cin>>k;
	cout<<"Ingrese "<<e<<" aristas (v1 v2 peso)"<<endl;
	vector<iii> aristas;
	int a,b,c;
	for(int x=0; x<e; x++){
		cin>>a>>b>>c;
		aristas.push_back(make_pair(c ,make_pair(a,b)));
	}
	sort(aristas.begin(), aristas.end());
	int costo=0,ar=0;
	Union u(v);
	vector<ii> subgraph;
	for(ui x=0; x<aristas.size();x++){
		if(!u.sameSet(aristas[x].second.first,aristas[x].second.second)){
			++ar;
			costo+=aristas[x].first;
			subgraph.push_back(ii(aristas[x].second.first,aristas[x].second.second));
			u.setUnion(aristas[x].second.first,aristas[x].second.second);
			if((v-ar)==k)break;
		}
	}
	cout<<"Subgrafo"<<endl;
	for(ui x=0; x<subgraph.size(); x++){
		cout<<subgraph[x].first<<" "<<subgraph[x].second<<endl;
	}
	cout<<"Minimun Spannig Forest "<<costo<<endl;
	return 0;
}
