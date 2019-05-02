#include <bits/stdc++.h>

using namespace std;

pair<int,int> getNextCoordinate(char c){
	if(c == 'N') return make_pair(-1,0);
	if(c == 'E') return make_pair(0,1);
	if(c == 'S') return make_pair(1,0);
	return make_pair(0,-1);
}

void exitOrLoop(pair<int,int> coor, vector<string> &ins, vector<vector<int>> &matrix){
	int steps = 0;
	bool outOfMatrix = false;
	while(true){
		if(!matrix[coor.first][coor.second]){
			matrix[coor.first][coor.second] = ++steps;
			pair<int,int> nextCoor = getNextCoordinate(ins[coor.first][coor.second]);
			int row = coor.first + nextCoor.first, col = coor.second + nextCoor.second;
			if(row < 0 || row >= matrix.size()) outOfMatrix = true;
			if(col < 0 || col >= matrix.back().size()) outOfMatrix = true;
			if(!outOfMatrix){
				coor.first = row, coor.second = col;
			}else{
				cout<<steps<<" step(s) to exit\n";
				return;
			}
		}else{
			int stepsBeforeLoop = matrix[coor.first][coor.second] - 1;
			int loopLength = steps-(stepsBeforeLoop);
			cout<<stepsBeforeLoop<<" step(s) before a loop of "<<loopLength<<" step(s)\n";
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int rows, columns, startingColumn;
	string line;
	while(cin>>rows>>columns>>startingColumn && (rows || columns || startingColumn)){
		vector<string> instructions;
		vector<vector<int>> matrix(rows, vector<int>(columns,0));
		--startingColumn;
		for(int i = 0; i<rows && cin>>line; i++) instructions.emplace_back(line);
		exitOrLoop(make_pair(0,startingColumn), instructions, matrix);
	}
	return 0;
}
