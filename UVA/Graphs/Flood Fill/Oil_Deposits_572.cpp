#include <bits/stdc++.h>

using namespace std;

int crow[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int ccol[] = { 0, 1, 1, 1, 0,-1,-1,-1};

struct Coor{
	int row, col;
	Coor(int row, int col):row(row), col(col){}
};

int depositSize(vector<string> &matrix, int x, int y){
	int size = 0;
	queue<Coor> q;
	q.push(Coor(x,y));
	while(!q.empty()){
		Coor c = q.front();
		q.pop();
		matrix[c.row][c.col] = '*';
		++size;
		for(int i = 0; i<8; i++){
			int row = c.row + crow[i], col = c.col + ccol[i];
			if(row < 0 || row>=matrix.size()) continue;
			if(col < 0 || col>=matrix[0].length()) continue;
			if(matrix[row][col] != '@') continue;
			q.push(Coor(row,col));
		}
	}
	return size;
}

int differentDeposits(vector<string> &matrix){
	int res = 0;
	for(int row = 0; row<matrix.size(); row++){
		for(int col = 0; col<matrix[0].length(); col++){
			if(matrix[row][col] == '@'){
				res+=depositSize(matrix,row,col)>0;
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	string line;
	while(cin>>m>>n && m){
		vector<string> matrix;
		while(m-- && cin>>line) matrix.emplace_back(line);
		cout<<differentDeposits(matrix)<<"\n";
	}
	return 0;
}