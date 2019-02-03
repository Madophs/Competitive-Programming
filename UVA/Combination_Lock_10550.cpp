#include <iostream>
#include <cmath>
using namespace std;
int horaria(int a, int b){
	if(b==a)return 0;
	if(a>b)return (a-b)*9;
	if(b>a)return ((40-b)+a)*9;
	return 0;
}
int anti(int a,int b){
	if(a==b)return 0;
	if(a>b)return ((40-a)+b)*9;
	if(a<b)return (b-a)*9;
	return 0;
}


int main(){
	int a=0,b=0,c=0,d=0;
	while(cin>>a>>b>>c>>d && (a || b ||c ||d)){
		cout<<(1080+horaria(a,b)+anti(b,c)+horaria(c,d))<<endl;
	}
	return 0;
}
