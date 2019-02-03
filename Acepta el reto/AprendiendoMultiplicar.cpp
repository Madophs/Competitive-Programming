#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int tc=0;
	int secuencia[10000];
	cin>>tc;
	while(tc--){
		int num=0,val=0;
		cin>>num;
		int i=-1, ia=-1,aux=0,res=0,multi=0,j=0;
		for(int x=0; x<num; x++){
			cin>>secuencia[x];
			if(secuencia[x]!=0)++multi;
			res=max(res,multi);
			i=res>aux?ia:i;
			if(secuencia[x]==0){
				multi=0;
				aux=res;
				ia=x;
			}
		}
		if(res!=0){
			cout<<res<<" -> ["<<i+1<<","<<(i+res)<<"]\n";
		}else{
			cout<<"SIGUE BUSCANDO\n";
		}
	}
	return 0;
}
