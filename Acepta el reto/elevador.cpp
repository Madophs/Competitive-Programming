#include <iostream>
using namespace std;
int main(){
	int piso=0,dist=0,ant=0;
	while(cin>>piso && piso>=0){
		dist=0;
		ant=piso;
		while(cin>>piso && piso!=-1){
			dist+=((ant<piso)?piso-ant:ant-piso);
			ant=piso;
		}
		cout<<dist<<endl;
	}
	return 0;
}
