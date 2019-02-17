#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int minimumTimeNeeded(vector< vector<int> > &grid, int &s,int &d){
	int ans = 0;
	for(int k = 0; k<grid.size(); k++){
		for(int i = 0; i<grid.size(); i++){
			for(int j = 0; j<grid.size(); j++){
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}
	for(int x = 0; x<grid.size(); x++){
		grid[x][x] = 0;
		ans = max(ans, grid[s][x] + grid[x][d]);	
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, buildings,roads,a,b,start,destination,test = 0;
	cin>>t;
	while(t--){
		cin>>buildings>>roads;
		vector< vector<int> > grid(buildings, vector<int>(buildings,INF));
		while(roads-- && cin>>a>>b)grid[a][b] = grid[b][a] = 1;
		cin>>start>>destination;
		cout<<"Case "<<++test<<": "<<minimumTimeNeeded(grid,start,destination)<<"\n";
	}	
	return 0;
}