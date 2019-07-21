#include <bits/stdc++.h>

using namespace std;

struct Position{
	int row, col;
	int currDirection;
	Position(){
		this->row = 0;
		this->col = 0;
		this->currDirection = 0;
	}
	
	void setDirection(char c){
		if(c == 'N'){
			currDirection = 0;
		}else if(c =='L'){
			currDirection = 1;
		}else if(c == 'S'){
			currDirection = 2;
		}else{
			currDirection = 3;
		}
	}

	void setCoordinates(int row, int col){
		this->row = row;
		this->col = col;
	}
	
	void move(char ins){
		int inc = ins == 'F' ? 1 : -1;
		switch (currDirection) {
			case 0:
				row += (inc*-1);
				break;
			case 1:
				col += inc;
				break;
			case 2:
				row += inc;
				break;
			case 3:
				col += (inc*-1);
				break;
		}
	}
	
	void performAction(char ins){
		if(ins == 'E'){
			--currDirection;
			if(currDirection < 0) currDirection = 3;
		}else if(ins == 'D'){
			++currDirection;
			if(currDirection > 3) currDirection = 0;
		}else{
			move(ins);	
		}
	}

	int getRow(){
		return row;
	}
	
	int getCol(){
		return col;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numRow, numCol, instructions, stickers;
	char cell;	
	string insLine;
	vector<string> matrix;
	Position pos;
	while(cin>>numRow>>numCol>>instructions){
		if(numRow == 0 && numCol == 0 && instructions == 0) break;
		matrix.assign(numRow, "");
		stickers = 0;
		for(int i = 0; i < numRow; ++i){
			for(int j = 0; j < numCol ; ++j){
				cin>>cell;
				matrix[i].push_back(cell);
				if(cell == 'N' || cell == 'S' || cell == 'L' || cell == 'O'){
					pos.setDirection(cell);
					pos.setCoordinates(i,j);
				}
			}
		}
		cin>>insLine;
		for(int i = 0; i < insLine.length(); ++i){
			pos.performAction(insLine[i]);
			if(pos.getRow() >= matrix.size() || pos.getRow() < 0){
				pos.performAction('B');
				continue;
			}
			if(pos.getCol() >= matrix.back().length() || pos.getCol() < 0){
				pos.performAction('B');
				continue;
			}
			if(matrix[pos.getRow()][pos.getCol()] == '#'){
				pos.performAction('B');
			}else if(matrix[pos.getRow()][pos.getCol()] == '*'){
				++stickers;
				matrix[pos.getRow()][pos.getCol()] = '.';
			}
		}
		cout<<stickers<<"\n";
	}
	return 0;
}
