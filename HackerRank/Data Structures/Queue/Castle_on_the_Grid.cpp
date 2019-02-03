#include <bits/stdc++.h>

using namespace std;


struct Coordinate{
	int x,y,distance;
	bool operator < (Coordinate c)const{
		if(distance == c.distance){
			if(x == c.x){
				return y > c.y;
			}
			return x > c.x;
		}
		return distance > c.distance;
	}
	Coordinate(int x, int y, int d):x(x),y(y),distance(d){}
};

int howManySteps(char **castle,int &d,int &x, int &y, int &xend, int &yend){
	priority_queue< Coordinate > q;
	int solution[d][d];
	memset(solution,-1,sizeof(solution));
	q.push(Coordinate(x,y,0));
	castle[x][y] = '*';
	while(!q.empty()){
		Coordinate coor = q.top();
		q.pop();
		solution[coor.x][coor.y] = coor.distance;
		if(coor.x == xend && coor.y == yend)return solution[coor.x][coor.y];
		for(int j = coor.y+1; j<d; j++){
			if(solution[coor.x][j]>-1 || castle[coor.x][j]=='*')continue;
			if(castle[coor.x][j]=='X' )break;
			Coordinate c(coor.x,j,coor.distance+1);
			castle[coor.x][j] = '*';
			q.push(c);
		}
		for(int j = coor.y-1; j>=0; j--){
			if(solution[coor.x][j]>-1 || castle[coor.x][j]=='*')continue;
			if(castle[coor.x][j]=='X' )break;
			Coordinate c(coor.x,j,coor.distance+1);
			castle[coor.x][j] = '*';
			q.push(c);
		}
		for(int i = coor.x+1; i<d; i++){
			if(solution[i][coor.y]>-1 || castle[i][coor.y]=='*')continue;
			if(castle[i][coor.y]=='X')break;
			Coordinate c(i,coor.y,coor.distance+1);
			castle[i][coor.y] = '*';
			q.push(c);
		}
		for(int i = coor.x-1; i>=0; i--){
			if(solution[i][coor.y]>-1 || castle[i][coor.y]=='*')continue;
			if(castle[i][coor.y]=='X')break;
			Coordinate c(i,coor.y,coor.distance+1);
			castle[i][coor.y] = '*';
			q.push(c);
		}
		
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dimensions;
	char c;
	cin>>dimensions;
	char **castle = new char *[dimensions];
	for(int x=0; x<dimensions; x++){
		castle[x] = new char[dimensions];
		for(int y=0; y<dimensions; y++){
			cin>>castle[x][y];
		}
	}
	int x,y,i,j;
	cin>>x>>y>>i>>j;
	cout<<howManySteps(castle, dimensions,x,y,i,j)<<endl;
	return 0;
}