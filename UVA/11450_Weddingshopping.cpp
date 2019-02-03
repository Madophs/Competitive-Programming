#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int m,c;
int precios[25][25];
int memo[210][25];

int tienda(int dinero, int g){
	if(dinero<0)return -9999999;
	if(g==c)return m-dinero;
	if(memo[dinero][g]!=-1)return memo[dinero][g];
	int res=-1;
	for(int x=1; x<=precios[g][0]; x++){
		res=max(res,tienda(dinero-precios[g][x],g+1));
	}
	return memo[dinero][g]=res;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		cin>>m>>c;
		for(int x=0; x<c;x++){
			cin>>precios[x][0];
			for(int y=1; y<=precios[x][0]; y++){
				cin>>precios[x][y];
			}
		}
		memset(memo,-1, sizeof(memo));
		int res=tienda(m,0);
		if(res<0){
			cout<<"no solution\n";
		}else{
			cout<<res<<"\n";
		}
	}
	return 0;
}
