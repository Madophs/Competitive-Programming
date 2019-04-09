#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	int matrix[101][101];
	while(cin>>size){
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				cin>>matrix[i][j];
				if(i > 0) matrix[i][j] += matrix[i-1][j];
				if(j > 0) matrix[i][j] += matrix[i][j-1];
				if(i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
			}
		}
		int ans = -1e9, sum;
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				for(int x = i; x<size; x++){
					for(int y = j; y<size; y++){
						sum = matrix[x][y];
						if(j > 0) sum -= matrix[x][j-1];
						if(i > 0) sum -= matrix[i-1][y];
						if(j > 0 && i > 0) sum += matrix[i-1][j-1];
						ans = max(ans,sum);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}