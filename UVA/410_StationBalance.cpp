#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
pair<int , int> ordenaPar(int a, int b, int *p);
int main(){
	std::ios_base::sync_with_stdio(false);
	string cadena;
	int set=0;
	while(getline(cin,cadena)){
		if(cadena.empty())break;
		if(set>0)cout<<"\n";
		int c,s;
		double am=0;
		stringstream tk(cadena);
		tk>>c;
		tk>>s;
		int esp[s];
		memset(esp, 0, sizeof(esp));
		for(int x=0; x<s; x++){
			cin>>esp[x];
			am+=esp[x];
		}
		am/=c;
		vector<int> aux;
		aux.assign(esp,esp+s);
		int dif=(2*c)-s;
		while(dif--){
			aux.push_back(0);
		}
		sort(aux.begin(),aux.end());
		vector< pair <int, int> >parejas;
		for(int x=0; x<aux.size()/2; x++){
			parejas.push_back(ordenaPar(aux[x],aux[2*c-(x+1)],esp));
		}
		cout<<"Set #"<<++set<<"\n";
		int cont=0;
		double cm=0, imb=0;
		for(int x=0; x<s; x++){
			for(int y=0; y<parejas.size();y++){
				cm=0;
				if(esp[x]==parejas[y].first){
					if(parejas[y].second!=0){
						cm=(double)(parejas[y].first+parejas[y].second);
						cout<<setw(2)<<cont<<right<<": "<<parejas[y].first<<" "<<parejas[y].second<<"\n";
					}else{
						cm=(double)(parejas[y].first);
						cout<<setw(2)<<cont<<right<<": "<<parejas[y].first<<"\n";
					}
					parejas.erase(parejas.begin()+y);
					cont++;
					imb+=abs(cm-am);
				}
			}
		}
		if(c>s){
			cm=0;
			for(int x=0; x<(c-s); x++){
				cout<<setw(2)<<cont<<right<<":\n";
				cont++;
				imb+=abs(cm-am);
			}
		}
		cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<imb<<"\n";
		cin.ignore();
	}
	cout<<"\n";
	return 0;
}

pair<int , int> ordenaPar(int a, int b, int *p){
	if(a==0){
		return make_pair(b,a);
	}
	for(int x=0; x<sizeof(p)/sizeof(int);x++){
		if(p[x]==a){
			return make_pair(a,b);
		}
		if(p[x]==b){
			return make_pair(b,a);
		}
	}
	return make_pair(a,b);
}
