#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
class Grafo{
	enum Color{neutro,rojo,azul};
public:
	map<int, vector<int> > hash;
	Grafo(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)inserta(x);
	}
	void inserta(int nom){
		vector<int> nuevo;
		hash.insert(make_pair(nom,nuevo));
	}
	void inAristas(int a, int b){
		map<int, vector<int> >::iterator iter = hash.find(a);
		map<int, vector<int> >::iterator iter2 = hash.find(b);
		iter->second.push_back(iter2->first);
		iter2->second.push_back(iter->first);
	}
	bool bipartito(){
		vector<int> color(noVer,-1);
		for(int y=0; y<noVer; y++){
			if(color[y]==-1){
				color[y]=0;
				queue<int> q;
				q.push(y);
				while(!q.empty()){
					int u=q.front();
					q.pop();
					map<int, vector<int> >::iterator iter = hash.find(u);
					for(int x=0; x<iter->second.size(); x++){
						if(color[iter->second[x]]==-1){
							q.push(iter->second[x]);
							color[iter->second[x]]=1-color[u];
						}else if(color[iter->second[x]]==color[u]){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
private:
	int noVer;
	vector<bool> visitado;
};
int main(){
	int v,e;
	string cadena;
	while(getline(cin,cadena) && !cadena.empty()){
		v=atoi(cadena.c_str());
		cin>>e;
		int a,b;
		Grafo g(v);
		while(e--){
			cin>>a>>b;
			g.inAristas(a,b);
		}
		cin.ignore();
		cout<<(g.bipartito()?"SI\n":"NO\n");
	}
	return 0;
}
