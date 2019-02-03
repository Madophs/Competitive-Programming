#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

bool ordenamineto(pair< int, int> p, pair<int, int > p2){
	if(p.second<p2.second) return true;
	return (p.second==p2.second && p.first<p2.first);
}
int main(){
	int c=0;
	while(cin>>c && c){
		string fecha="";
		vector< pair< int, int> > lista;
		for(int x=0; x<c; x++){
			cin>>fecha;
			char *p = strtok((char*)fecha.c_str(), "/");
			int a[3];
			for(int y=0; p!=NULL; y++){
				a[y]=atoi(p);
				p=strtok(NULL,"/");
			}
			pair< int, int> nuevo = make_pair(a[0],a[1]);
			lista.push_back(nuevo);
		}
		sort(lista.begin(),lista.end(),ordenamineto);
		bool existe = false;
		for(int x=1; x<lista.size(); x++){
			if(lista[x-1].first==lista[x].first && lista[x-1].second==lista[x].second){
				existe=true;
				break;
			}
		}
		cout<<(existe?"SI":"NO")<<endl;
	}
}
