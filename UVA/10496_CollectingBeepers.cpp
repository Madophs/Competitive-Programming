#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n,dist[11][11],memo[11][1<<11];
int tsp(int pos, int bitmask){
	if(bitmask == (1<<(n+1))-1){
		return dist[pos][0];
	}
	if(memo[pos][bitmask]!=-1)return memo[pos][bitmask];
	int res=1e9;
	for(int next=0; next<=n;next++){
		if(next!=pos && !(bitmask&(1<<next))){
			res=min(res,dist[pos][next] +tsp(next, bitmask|(1<<next)));
		}
	}
	return memo[pos][bitmask]=res;
}
int main(){
	int tc,xtam,ytam,i[11],j[11];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&xtam,&ytam);
		scanf("%d %d",&i[0],&j[0]);
		scanf("%d",&n);
		for(int w=1; w<=n;w++)scanf("%d %d",&i[w],&j[w]);
		for(int x=0; x<=n;x++){
			for(int y=0; y<=n;y++){
				dist[x][y]= abs(i[x]-i[y])+abs(j[x]-j[y]);
			}
		}
		memset(memo,-1,sizeof(memo));
		printf("The shortest path has length %d\n",tsp(0,1));
	}
	return 0;
}
