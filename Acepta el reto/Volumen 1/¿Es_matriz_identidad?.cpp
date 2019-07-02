#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dimension, valor;
	while(cin>>dimension && dimension){
		bool matrizIndentidad = true;
		for(int i = 0; i < dimension; i++){
			for(int j = 0; j < dimension; j++){
				cin>>valor;
				if(i == j){
					if(valor != 1) matrizIndentidad = false;
				}else{
					if(valor != 0) matrizIndentidad = false;
				}
			}
		}
		cout<<(matrizIndentidad ? "SI\n": "NO\n");
	}
	return 0;
}
