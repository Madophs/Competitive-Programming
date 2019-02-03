#include <iostream>

using namespace std;
int cuadrados(int);
int rectangulos(int);
int main(){
	int num=0;
	while(cin>>num && num){
		cout<<cuadrados(num)<<" "<<rectangulos(num)<<endl;
	}
	return 0;
}
int cuadrados(int val){
	int res=0;
	if(val==1) return 1;
	for(int x=2; x<=val; x++){
		res+=(x*x);
	}
	return res+1;
}
int rectangulos(int val){
	int res=val,salto=2;
	if(val==1) return 1;
	while(true){
		for(int x=salto; x<=val; x++){
			++res;
		}
		if(salto>=val)break;
		++salto;
	}
	return res*res;
}
