#include <bits/stdc++.h>
#define bomb 1e9

using namespace std;

const int size = 101;
int mines[size][size];
struct point{
	int x,y;
	point(int x, int y):x(x),y(y){}
};
int cx[8] = {0,1,1, 1, 0,-1,-1,-1};
int cy[8] = {1,1,0,-1,-1,-1, 0, 1};
void minesweeper(vector<point> &vec,int limitx ,int limity){
	for(auto iter = vec.begin(); iter != vec.end(); iter++){
		auto ref = *iter;
		for(int x=0; x<8; x++){
			if((ref.x+cx[x])<limitx && (ref.x+cx[x])>=0 && (ref.y+cy[x])>=0 && (ref.y+cy[x])<limity){
				if(mines[ref.x+cx[x]][ref.y+cy[x]]==bomb)continue;
				++mines[ref.x+cx[x]][ref.y+cy[x]];
			}
		}
	}
}

void printMatrix(int row, int col){
	for(int x=0; x<row; x++){
		for(int y=0; y<col; y++){
			if(mines[x][y]==bomb){
				cout<<'*';
			}else{
				cout<<mines[x][y];
			}
		}
		cout<<"\n";
	}
}
int main(){
	int row,col,field=0;
	bool salto = false;
	string line;
	while(cin>>row>>col && (row || col)){
		if(salto)cout<<"\n";
		salto = true;
		vector<point> vec;
		for(int x=0; x<row; x++){
			cin>>line;
			for(int y=0; y<line.length(); y++){
				if(line.at(y)=='*'){
					mines[x][y]=bomb;
					vec.push_back(point(x,y));
				}else{
					mines[x][y]=0;
				}
			}
		}
		minesweeper(vec,row,col);
		cout<<"Field #"<<++field<<":\n";
		printMatrix(row,col);
	}
	return 0;
}
