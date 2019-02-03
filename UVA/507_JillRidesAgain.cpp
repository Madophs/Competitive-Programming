#include <iostream>
#include <cmath>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	int tc,paradas,c=0;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&paradas);
		int ruta[paradas+1];
		int sum=0,res=0,i=-1,j=0,aux=0,x=0,ia=-1;
		for(x=0; x<paradas-1; x++){
			scanf("%d",&ruta[x]);
			sum+=ruta[x];
			res=max(sum,res);
			bool si=false;
			if(res==sum){
				if(aux<res || abs(x-ia)>abs(j-i)){
					j=x;
					si=true;
				}
			}
			i=res==aux && !si?i:ia;
			if(sum<0){
				sum=0;
				ia=x;
				aux=res;
			}
		}
		if(res>0){
			printf("The nicest part of route %d is between stops %d and %d\n",++c,i+2,j+2);
		}else{
			printf("Route %d has no nice parts\n",++c);
		}
	}
	return 0;
}
