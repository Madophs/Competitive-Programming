#include <bits/stdc++.h>

using namespace std;
bool letras[30];
struct vertice{
	vector< vertice* > adj;
	char nombre;
	vertice(char nom):nombre(nom){}
};

class Grafo{
public:
	map< char, vertice*> hash;
	Grafo(char c):limite(c){
		for(char x='A'; x<=c;x++){
			insertar(x);
		}
	}
	void insertar(char nombre){
		vertice *v = new vertice(nombre);
		hash.insert(make_pair(nombre,v));
	}
	void insertarArco(char a, char b){
		map<char, vertice*>::iterator iter = hash.find(a);
		map<char, vertice*>::iterator iter2 = hash.find(b);
		iter->second->adj.push_back(iter2->second);
		iter2->second->adj.push_back(iter->second);
	}
	int componentes(){
		int can=0;
		for(int x='A'; x<=limite;x++){
			if(!letras[x-'A']){
				dfs(x);
				++can;
			}
		}
		return can;
	}
	void dfs(char ver){
		letras[ver-'A']=true;
		map<char, vertice*>::iterator iter = hash.find(ver);
		for(int x=0; x<iter->second->adj.size(); x++){
			if(!letras[iter->second->adj[x]->nombre-'A']){
				dfs(iter->second->adj[x]->nombre);
			}
		}
	}
private:
	char limite;
};
int main(){
	ios_base::sync_with_stdio(true);
	int tc;
	string nodos;
	cin>>tc;
	cin.ignore();
	while(tc--){
		char c;
		cin>>nodos;
		c=nodos[0];
		Grafo g(c);
		cin.get();
		while(getline(cin,nodos) && !nodos.empty()){
			g.insertarArco(nodos.at(0),nodos.at(1));
		}
		memset(letras,false,sizeof(letras));
		cout<<g.componentes()<<(tc==0?"\n":"\n\n");
	}
	return 0;
}