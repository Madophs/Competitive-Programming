#include <bits/stdc++.h>

using namespace std;

const int length = 8;
int width, height;
int cx[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int cy[] = { 0, 1, 1, 1, 0,-1,-1,-1};

int bodiesOfWater(vector<string> grid, int i, int j){
	int sum = 1;
	queue< pair<int,int> > coordinates;
	grid[--i][--j] = 'X';
	coordinates.push( make_pair(i,j));
	while(!coordinates.empty()){
		pair<int, int> coor = coordinates.front();
		coordinates.pop();
		for(int x = 0; x<length; x++){
			if(coor.first+cx[x]< 0 || coor.first+cx[x]>=height) continue;
			if(coor.second+cy[x]< 0 || coor.second+cy[x]>=width) continue;
			if(grid[coor.first+cx[x]][coor.second+cy[x]] == 'W'){
				++sum;
				grid[coor.first+cx[x]][coor.second+cy[x]] = 'X';
				coordinates.push( make_pair(coor.first+cx[x], coor.second+cy[x]) );
			}
		}
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> grid(120,"");
	int t;
	bool jump = false;
	string line;
	cin>>t;
	cin.ignore();
	while(t--){
		if(jump){
			cout<<'\n';
		}else{
			cin.ignore();
			jump = true;
		}
		width = height = 0;
		while(getline(cin,line) && !line.empty()){
			if(line[0] == 'W' || line[0] == 'L'){
				grid[height++] = line;
			}else{
				stringstream ss(line);
				int i, j;
				ss>>i>>j;
				width = grid[0].length();
				cout<<bodiesOfWater(grid,i,j)<<'\n';
			}
		}
	}
	return 0;
}