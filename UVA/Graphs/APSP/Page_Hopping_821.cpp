#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int matrix[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, size , t = 0;
	while(cin>>a>>b && (a || b)){
		a--,b--;
		for(int i = 0; i<101; i++){
			for(int j = 0; j<101; j++){
				if(i == j){
					matrix[i][j] = 0;
				}else{
					matrix[i][j] = INF;
				}
			}
		}
		size = 0;
		size = max(max(a,b),size);
		matrix[a][b] = 1;
		while(cin>>a>>b && (a || b)){
			a--,b--;
			size = max(max(a,b),size);
			matrix[a][b] = 1;
		}
		++size;
		int k,i,j;
		for(int k = 0; k<size; k++){
			for(int i = 0; i<size; i++){
				for(int j = 0; j<size; j++){
					matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
				}
			}
		}
		double sum = 0, edges = 0;
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				if(matrix[i][j]!=INF && matrix[i][j]){
					sum+=matrix[i][j];
					++edges;
				}
			}
		}
		cout<<fixed<<setprecision(3)<<"Case "<<++t<<": average length between pages = "<<(sum/edges)<<" clicks\n";
	}
	return 0;
}