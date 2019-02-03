#include <bits/stdc++.h>

using namespace std;

int crow[] = {-1, 0, 1, 0};
int ccol[] = { 0, 1, 0,-1};

struct Location{
	int row,col;
	Location(int row, int col):row(row),col(col){}
};

int getLandSize(int valRow, int valCol,vector<string> &mapa, int &width, int &height,char land){
	int landSize = 1;
	queue< Location > q;
	mapa[valRow][valCol] = ' ';
	q.push(Location(valRow, valCol));
	while(!q.empty()){
		Location coor = q.front();
		q.pop();
		for(int x=0; x<4; x++){
			int tempRow = coor.row + crow[x], tempCol = coor.col + ccol[x];
			if(tempRow >= height) continue;
			if(tempCol >= width) tempCol = 0;
			if(tempRow < 0) continue;
			if(tempCol < 0) tempCol = width-1;
			if(mapa[tempRow][tempCol] == land){
				mapa[tempRow][tempCol] = ' ';
				q.push(Location(tempRow, tempCol));
				++landSize;
			}
		}
	}
	return landSize;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> mapa(22,"");
	int width, height, row,col;
	char land = 'l';
	while(cin>>height>>width){
		for(int x=0; x<height; x++)cin>>mapa[x];
		cin>>row>>col;
		land = mapa[row][col];
		getLandSize(row,col,mapa,width,height,land);
		int ans = 0;
		for(int x=0; x<height; x++){
			for(int y=0; y<width; y++){
				if(mapa[x][y] != land)continue;
				ans = max(ans,getLandSize(x,y,mapa,width,height,land));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}