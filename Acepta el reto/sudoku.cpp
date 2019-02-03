#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(true);
	int tc;
	scanf("%d",&tc);
	int sudoku[10][10];
	memset(sudoku,0,sizeof(sudoku));
	while(tc--){
		bool resuelto =true;
		set< int ,less< int > > repeticion[9][1];
		for(int x=1;x<10;x++){
			set< int, less< int > > hash;
			for(int y=1; y<10;y++){
				scanf("%d",&sudoku[x][y]);
				hash.insert(sudoku[x][y]);
				repeticion[x-1][0].insert(sudoku[x][y]);
				if(x>1)sudoku[x][y]+=sudoku[x-1][y];
				if(y>1)sudoku[x][y]+=sudoku[x][y-1];
				if(y>1 && x>1)sudoku[x][y]-=sudoku[x-1][y-1];
			}
			if(hash.size()!=9){
				resuelto=false;
			}
			hash.clear();
		}
		for(int x=0; x<9 && resuelto; x++){
			if(repeticion[x][0].size()!=9){
				resuelto=false;
			}
			repeticion[x][0].clear();
		}
		for(int x=1; x<10 && resuelto;x++){
			if(sudoku[x][9]-sudoku[x-1][9]!=45){
				resuelto=false;
			}
		}
		for(int x=1; x<10 && resuelto;x++){
			if(sudoku[9][x]-sudoku[9][x-1]!=45){
				resuelto=false;
			}
		}
		int suma=45;
		for(int x=3; x<10 && resuelto;x+=3){
			suma=45*(x/3);
			for(int y=3; y<10 && resuelto; y+=3){
				if(sudoku[x][y]!=suma*(y/3))resuelto=false;
			}
		}

		printf("%s\n",(resuelto?"SI":"NO"));
	}
	return 0;
}
