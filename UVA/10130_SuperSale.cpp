#include <iostream>
#include <cstring>
using namespace std;
int limite=0;
int valores[2][1000],memo[1010][50];
int optimo(int id, int esp){
	if(esp<=0 || id ==limite)return 0;
	if(memo[id][esp]!=-1)return memo[id][esp];
	if(valores[1][id]>esp) return memo[id][esp]=optimo(id+1,esp);
	return memo[id][esp] = max(optimo(id+1,esp), valores[0][id]+optimo(id+1,esp-valores[1][id]));
}
int main(){
	ios_base::sync_with_stdio(true);
	int tc;
	scanf("%d",&tc);
	while(tc--){
		memset(memo,-1,sizeof(memo));
		scanf("%d",&limite);
		for(int x=0; x<limite;x++){
			scanf("%d",&valores[0][x]);
			scanf("%d",&valores[1][x]);
		}
		int personas=0,mochila=0,res=0;
		scanf("%d",&personas);
		while(personas--){
			scanf("%d",&mochila);
			res+=optimo(0,mochila);
		}
		printf("%d\n",res);
	}
	return 0;
}
