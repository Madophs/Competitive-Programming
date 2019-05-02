#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8;
int crow[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int ccol[] = { 0, 1, 1, 1, 0,-1,-1,-1};

struct Coor{
	int row, col;
	Coor(int row, int col){
		this->row = row;
		this->col = col;
	}
};

bool searchForEagles(vector<string> &image, Coor coor){
	queue<Coor> order;
	order.push(coor);
	while(!order.empty()){
		Coor c = order.front();
		order.pop();
		image[c.row][c.col] = '0';
		for(int i = 0; i<SIZE; i++){
			int row = c.row + crow[i], col = c.col + ccol[i];
			if(row < 0 || row == image.size()) continue;
			if(col < 0 || col == image.size()) continue;
			if(image[row][col] == '0') continue;
			order.push(Coor(row,col));
		}
	}
	return true;
}

int countEagles(vector<string> &image){
	int eagles = 0;
	for(int row = 0; row<image.size(); row++){
		for(int col = 0; col<image.size(); col++){
			if(image[row][col] == '0') continue;
			eagles += searchForEagles(image, Coor(row,col));
		}
	}
	return eagles;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size, imageCount = 0;
	string line;{}
	vector<string> image;
	while(cin>>size){
		image.clear();
		for(int i = 0; i<size && cin>>line; i++) image.emplace_back(line);
		cout<<"Image number "<<++imageCount<<" contains "<<countEagles(image)<<" war eagles.\n";
	}
	return 0;
}
