#include <iostream>
using namespace std;

int main(){
	int m=0;
	unsigned int *molinos = new unsigned int[1000001];
	while(scanf("%d",&m) &&m){
		unsigned long ant=0;
		int val=0;
		for(int x=1; x<=m; x++){
			scanf("%d",&val);
			ant+=static_cast<unsigned long>(val);
			molinos[x]=static_cast<unsigned int>(ant);
		}
		int t=0;
		scanf("%d",&t);
		int i=0,j=0;
		while(t--){
			scanf("%d %d",&i,&j);
			if(i==1 && j==m){
				printf("%d\n",ant);
			}else{
				printf("%d\n",molinos[j]-molinos[i-1]);
			}
		}

	}
	return 0;
}
