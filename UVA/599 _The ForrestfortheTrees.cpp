#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

struct vertice{
	string nombre;
	bool conectado;
	vertice(string nom,bool con):nombre(nom),conectado(con){}
};

class Grafo{
public:
	map< string, vertice> graph;
	vector< pair< string, string> > arcos;
	void agregarVertice(string &ver,bool con){
		map< string, vertice>::iterator iter = graph.find(ver);
		if(iter==graph.end()){
			vertice v(ver,con);
			graph.insert(map< string, vertice>::value_type(ver, v));
		}
	}

	void agregarArco(string &ver1,string &ver2){
		map< string, vertice>::iterator iter = graph.find(ver1);
		map< string, vertice>::iterator iter2 = graph.find(ver2);
		if(iter==graph.end()) agregarVertice(ver1,true);
		if(iter2==graph.end()) agregarVertice(ver2,true);
		pair< string, string> conec = make_pair(ver1,ver2);
		arcos.push_back(conec);
	}
};
int main(){
	int c=0;
	cin>>c;
	while(c--){
		Grafo grafo;
		string cad="";
		while(cin>>cad && cad.at(0)!='*'){
			string ver1=cad.substr(1,1);
			string ver2=cad.substr(3,1);
			grafo.agregarArco(ver1,ver2);
		}
		cin>>cad;
		char *p= std::strtok((char*)cad.c_str(),",");
		while(p!=NULL){
			string c=p;
			grafo.agregarVertice(c,false);
			p=strtok(NULL,",");
		}
		int arboles=0,acorns=0;
		for(map<string, vertice>::iterator iter = grafo.graph.begin(); iter!=grafo.graph.end(); iter++){
			if(!iter->second.conectado){
				++acorns;
			}
		}
		cout<<"There are "<<((grafo.graph.size())-grafo.arcos.size()-acorns)<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
	}
	return 0;
}
