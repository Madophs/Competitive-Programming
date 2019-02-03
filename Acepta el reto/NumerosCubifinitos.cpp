#include <iostream>
#include <sstream>
#include <list>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int num=0;
	while(cin>>num && num){
		string aux =static_cast<ostringstream*>( &(ostringstream() << num) )->str();
		list<int> lista;
		int res=0;
		lista.push_back(num);
		bool cubo=false;
		while(true){
			res=0;
			if(num==1){
				cubo=true;
				break;
			}
			for(int x=0; x<aux.length(); x++){
				res+=std::pow((aux[x]-'0'),3);
			}
			if(res==1) {
				lista.push_back(res);
				cubo=true;
				break;
			}
			if(std::find(lista.begin(),lista.end(),res)!=lista.end()){
				lista.push_back(res);
				break;
			}
			lista.push_back(res);
			aux =static_cast<ostringstream*>( &(ostringstream() << res) )->str();
		}
		int pos=0;
		for(list<int>::iterator iter = lista.begin(); iter!=lista.end(); iter++){
			cout<<*iter<<((pos+1)==lista.size()?" -> ": " - ");
			++pos;
		}
		cout<<((cubo)?"cubifinito.":"no cubifinito.")<<endl;
	}
	return 0;
}
