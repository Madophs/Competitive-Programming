#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef pair<int, pair<int,int> > iii;
typedef pair<int,int> ii;

int crow[] = {-1, 0, 1, 0};
int ccol[] = { 0, 1, 0,-1};

int shortestDistance(int numRows, int numCols, vector< vector<int> > &maze){
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	vector< vector<int> > cellsDistance(numRows,vector<int>(numCols,inf));
	pq.push(iii(0,ii(0,0)));
	cellsDistance[0][0] = 0;
	while(!pq.empty()){
		iii cell = pq.top();
		pq.pop();
		if(cell.first > cellsDistance[cell.second.first][cell.second.second])continue;
		for(int x=0; x<4; x++){
			int row = cell.second.first + crow[x],  col = cell.second.second + ccol[x];
			if(row<0 || row>=numRows) continue;
			if(col<0 || col>=numCols) continue;
			if(cellsDistance[cell.second.first][cell.second.second] + maze[row][col] < cellsDistance[row][col]){
				cellsDistance[row][col] = maze[row][col] + cellsDistance[cell.second.first][cell.second.second];
				pq.push(iii(cellsDistance[row][col],ii(row,col)));
			}
		}
	}
	return cellsDistance[numRows-1][numCols-1] + maze[0][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numRows, numCols,maces;
	cin>>maces;
	while(maces-- && cin>>numRows>>numCols){
		vector< vector<int> > maze(numRows,vector<int>(numCols,0));
		for(int row = 0; row < maze.size(); row++){
			for(int col = 0; col< maze[0].size(); col++){
				cin>>maze[row][col];
			}
		}
		int ans = shortestDistance(numRows, numCols, maze);
		cout<<ans<<'\n';
	}
	return 0;
}