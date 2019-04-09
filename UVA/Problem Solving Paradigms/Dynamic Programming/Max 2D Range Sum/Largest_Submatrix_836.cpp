#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, size;
	int matrix[30][30];
	string line;
	cin>>tests;
	for(int t = 0;tests--;t++){
		cin>>line;
		size = line.length();
		for(int i = 0; i<size; i++){
			matrix[0][i] = line[i] == '0' ? 0 : 1;
			if(i>0) matrix[0][i] += matrix[0][i-1];
		}
		for(int i = 1; i<size; i++){
			cin>>line;
			for(int j = 0; j<size; j++){
				matrix[i][j] = line[j] == '0' ? 0 : 1;
				if(i>0) matrix[i][j] += matrix[i-1][j];
				if(j>0) matrix[i][j] += matrix[i][j-1];
				if(i>0 && j>0) matrix[i][j] -= matrix[i-1][j-1];
			}
		}
		int ans = 0;
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				for(int x = i; x<size; x++){
					for(int y = j; y<size; y++){
						int sum = matrix[x][y];
						int width = y-j+1, height = x-i+1;
						int area = width*height; 
						if(i>0) sum -= matrix[i-1][y];
						if(j>0) sum -= matrix[x][j-1];
						if(i>0 && j>0) sum += matrix[i-1][j-1];
						if(area == sum)
							ans = max(ans,sum); 
					}
				}
			}
		}
		if(t)cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}