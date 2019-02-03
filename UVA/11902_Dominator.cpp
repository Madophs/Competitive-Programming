#include <bits/stdc++.h>

using namespace std;
int c=0;
struct vertice{
	vector< vertice*> adj;
	int nombre;
	bool dominador,independiente;
	vertice(int nom):nombre(nom),dominador(false),independiente(true){}
};

class Grafo{
public:
	map< int, vertice*> hash;
	Grafo(int tam){
		vector<bool> aux(tam,false);
		this->visitado=aux;
		this->noVertices=tam;
		matriz = new char *[tam];
		for(int x=0; x<tam;x++){
			inserta(x);
			matriz[x] = new char[tam];
		}
	}
	void inserta(int nombre){
		vertice *v = new vertice(nombre);
		hash.insert(map< int, vertice*>::value_type(nombre,v));
	}
	void insertaArco(int de, int hacia){
		map< int, vertice*>::iterator iter=hash.find(de);
		map< int, vertice*>::iterator iter2=hash.find(hacia);
		iter->second->adj.push_back(iter2->second);
		iter2->second->independiente=false;
	}
	void iniciarMatriz(int x, int y){
		matriz[x][y]='N';
	}
	void generaMatriz(){
		vector<bool>aux=visitado;
		dfs(0,dependientes);
		vector<int>::iterator dif;
		sort(dependientes.begin(),dependientes.end());
		for(int x=0; x<dependientes.size();x++){
			matriz[0][dependientes[x]]='Y';
		}
		for(int x=1; x<dependientes.size();x++){
			visitado=aux;
			map< int, vertice*>::iterator iter = hash.find(dependientes[x]);
			vector<int> comp,res(200);
			iter->second->dominador=true;
			dfs(0,comp);
			sort(comp.begin(),comp.end());
			dif=std::set_difference(dependientes.begin(),dependientes.end(),comp.begin(),comp.end(),res.begin());
			res.resize(dif-res.begin());
			for(int d=0; d<res.size();d++){
				matriz[dependientes[x]][res[d]]='Y';
			}
			iter->second->dominador=false;
		}
	}
	void dfs(int ver,vector<int> &depen){
		visitado[ver]=true;
		depen.push_back(ver);
		map<int , vertice*>::iterator iter = hash.find(ver);
		for(int x=0; x<iter->second->adj.size();x++){
			if(!visitado[iter->second->adj[x]->nombre] && !iter->second->adj[x]->dominador){
				dfs(iter->second->adj[x]->nombre,depen);
			}
		}
	}
	void imprimeMatriz(){
		printf("Case %d:\n",++c);
		string cadena="-";
		if(noVertices>1){
			cadena.assign(noVertices*2-1,'-');
		}
		printf("+%s+\n",cadena.c_str());
		for(int x=0; x<noVertices; x++){
			for(int y=0; y<noVertices;y++){
				printf("|%c",matriz[x][y]);
			}
			printf("|");
			printf("\n");
			printf("+%s+\n",cadena.c_str());
		}
	}
private:
	vector<bool> visitado;
	vector< int > dependientes;
	int noVertices;
	char **matriz;
};
int main() {
	int tc,tam,val;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&tam);
		Grafo g(tam);
		for(int x=0; x<tam;x++){
			for(int y=0; y<tam; y++){
				scanf("%d",&val);
				g.iniciarMatriz(x,y);
				if(val==1)g.insertaArco(x,y);
			}
		}
		g.generaMatriz();
		g.imprimeMatriz();
	}
    return 0;
}
