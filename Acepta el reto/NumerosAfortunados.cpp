#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	vector< vector<int> > afortunados;
	vector< int >primeros;
	for(int x=2; x<=100000;x+=2)primeros.push_back(x);
	int salto=2;
	afortunados.push_back(primeros);
	while(salto<primeros.size()){
		for(int x=0; x<primeros.size();x+=salto){
			if(x%salto==0)primeros.erase(primeros.begin()+x);
		}
		++salto;
		afortunados.push_back(primeros);
	}
	int num=0;
	while(scanf("%d",&num) && num){
		int div=1,aux=num;
		while(div<num){
			++div;
			int aux=ceil((double)num/(double)div);
			num=num-aux;
		}
		vector<int> vec(afortunados[div-2].begin(),afortunados[div-2].begin()+num);
		printf("%d:",aux);
		for(vector<int>::reverse_iterator iter=vec.rbegin(); iter!=vec.rend();iter++){
			printf(" %d",*iter);
		}
		printf("\n");
	}
	return 0;
}
