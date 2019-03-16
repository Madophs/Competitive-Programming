#include <bits/stdc++.h>

using namespace std;

int crow[] = {-1, 0, 1, 0};
int ccol[] = { 0, 1, 0,-1};

struct Coor{
	int row,col;
	Coor(int row, int col):row(row), col(col){}
};

void fillBattleship(vector<string> &matrix, int row, int col){
	queue<Coor> q;
	q.push(Coor(row,col));
	while(!q.empty()){
		Coor c = q.front();
		q.pop();
		matrix[c.row][c.col] = '.';
		for(int i = 0; i<4; i++){
			int row = crow[i] +c.row, col = ccol[i] + c.col;
			if(row < 0 || row>=matrix.size()) continue;
			if(col < 0 || col>=matrix[0].length()) continue;
			if(matrix[row][col] == '.') continue;
			q.push(Coor(row,col));
		}
	}
}
int battleships(vector<string> &matrix){
	int ans = 0;
	for(int row = 0; row<matrix.size(); row++){
		for(int col = 0; col<matrix[0].length(); col++){
			if(matrix[row][col] == 'x'){
				fillBattleship(matrix,row,col);
				++ans;
			}
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests,size;
	string line;
	cin>>tests;
	for(int t = 1; t<=tests; t++){
		cin>>size;
		vector<string> matrix;
		while(size-- && cin>>line) matrix.emplace_back(line);
		cout<<"Case "<<t<<": "<<battleships(matrix)<<"\n";
	}
	return 0;
}