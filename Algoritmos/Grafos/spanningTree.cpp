#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int> ii;
enum estado{Explorado,Visitado,NoVisitado};

struct vertice{
	vector< vertice* > adj;
	int nombre;
	vertice(int nom):nombre(nom){}
};

class Grafo{
	typedef map< int, vertice*> tabla;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		iniciarGrafo(noVer);
	}
	void inserta(int nom=0){
		if(nom<noVer && nom<hash.size()){
			nom=noVer;
			++noVer;
		}
		vertice *v = new vertice(nom);
		hash.insert(make_pair(nom,v));
	}
	void insertaArco(int a, int b){
		tabla::iterator iter = hash.find(a);
		tabla::iterator iter2 = hash.find(b);
		if(iter==hash.end() || iter2==hash.end()){
			cout<<"Una de las arista no exite"<<endl;
			return;
		}
		iter->second->adj.push_back(iter2->second);
	}
	void buscaAristas(int ver){
		verifica.assign(noVer,NoVisitado);
		padre.assign(noVer,-1);
		dfs(ver);
	}
	void dfs(int ver){
		verifica[ver]=Explorado;
		tabla::iterator iter = hash.find(ver);
		for(unsigned int x=0; x<iter->second->adj.size();x++){
			if(verifica[iter->second->adj[x]->nombre]==NoVisitado){
				padre[iter->second->adj[x]->nombre]=ver;
				dfs(iter->second->adj[x]->nombre);
			}else if(verifica[iter->second->adj[x]->nombre]==Explorado){
				if(iter->second->adj[x]->nombre==padre[ver]){
					cout<<"Two ways :("<<iter->second->adj[x]->nombre<<","<<ver<<") : ("<<ver<<","<<iter->second->adj[x]->nombre<<").\n";
				}else{
					cout<<"Back edge: ("<<ver<<","<<iter->second->adj[x]->nombre<<").\n";
				}
			}else{
				cout<<"Foward/Cross edge: ("<<ver<<","<<iter->second->adj[x]->nombre<<").\n";
			}
		}
		verifica[ver]=Visitado;
	}
	void cambiarTam(int nuevoTam){
		if(nuevoTam<=noVer){
			cout<<"El tamaño del grafo actual es menor o equivalente al tamaño actual\nDesea sobre escribir el grafo actual?\n1.-Si 2.-No\n";
			int op;
			cin>>op;
			switch(op){
			case 1:
				iniciarGrafo(nuevoTam);
				cout<<"Grafo reemplazado con exito"<<endl;
				break;
			case 2:
				cout<<"Eso es todo si algo funciona mejor no moverle"<<endl;
				break;
			default:
				cout<<"Dejame adivinar estas retando a un programa de computadora?"<<endl;
				break;
			}
		}
	}
	void insertarNVertices(int cant){
		while(cant--)inserta();
	}
	void info(){
		cout<<"Numero de vertice: "<<noVer<<endl;
		cout<<"Conectividad"<<endl;
		for(int x=0; x<noVer; x++){
			tabla::iterator iter = hash.find(x);
			cout<<x<<":";
			for(unsigned int y=0; y<iter->second->adj.size(); y++){
				cout<<" "<<iter->second->adj[y]->nombre;
			}
			cout<<endl;
		}
	}
private:
	int noVer;
	vector<ii> edges;
	vector<estado> verifica;
	vector<int> padre;

	void nuevoGrafo(){
		hash.clear();
		noVer=0;
	}
	void iniciarGrafo(int tam){
		nuevoGrafo();
		noVer=tam;
		for(int x=0; x<tam; x++)inserta(x);
	}
};
int main(){

	cout<<"Depth First Search Spannig Tree\n";
	int op;
	cout<<"Ingresa el numero de vertices"<<endl;
	cin>>op;
	Grafo g(op);
	do{
		cout<<"Insertar vertice\n2.-Insertar n vertices\n3.-Insertar arcos\n4.-Buscar Aristas\n5.-NuevoGrafo\n6.-Informacion del grafo\n0.-Salir"<<endl;
		cin>>op;
		switch(op){
		case 1:
			g.inserta();
			break;
		case 2:
			int num;
			cout<<"Numero de vertice a ingresar"<<endl;
			cin>>num;
			g.insertarNVertices(num);
			break;
		case 3:
			int a,b;
			cout<<"Insertar arcos"<<endl;
			while(cin>>a>>b && a>=0 && b>=0)g.insertaArco(a,b);
			break;
		case 4:
			int inicio;
			cout<<"Ingresa vertice inicial para iniciar la busqueda de aristas"<<endl;
			cin>>inicio;
			g.buscaAristas(inicio);
			break;
		case 5:
			int tam;
			cout<<"Tamaño del nuevo grafo"<<endl;
			cin>>tam;
			g.cambiarTam(tam);
			break;
		case 6:
			g.info();
			break;
		case 0:
			cout<<"Hasta la vista baby"<<endl;
			break;
		default:
			cout<<"Option invalida"<<endl;
			break;
		}
	}while(op!=0);
}
