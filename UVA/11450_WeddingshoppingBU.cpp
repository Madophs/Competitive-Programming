#include <iostream>
#include <cstring>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int precios[25][25];
	bool memo[25][210];
	int tc,m,c;
	cin>>tc;
	while(tc--){
		cin>>m>>c;
		for(int x=0; x<c; x++){
			cin>>precios[x][0];
			for(int y=1; y<=precios[x][0]; y++){
				cin>>precios[x][y];
			}
		}
		memset(memo,false,sizeof(memo));
		for(int x=1; x<=precios[0][0]; x++){
			if(m-precios[0][x]>=0){
				memo[0][m-precios[0][x]]=true;
			}
		}
		for(int x=1; x<c; x++){
			for(int y=0; y<m;y++){
				if(memo[x-1][y]){
					for(int w=1;w<=precios[x][0];w++){
						if(y-precios[x][w]>=0){
							memo[x][y-precios[x][w]]=true;
						}
					}
				}
			}
		}

		int dinero=0;
		for(dinero=0; dinero<=m &&!memo[c-1][dinero]; dinero++);
		if(dinero==m+1){
			cout<<"no solution\n";
		}else{
			cout<<(m-dinero)<<"\n";
		}
	}
	return 0;
}
