#include <bits/stdc++.h>

using namespace std;

int upperX, upperY;
set<pair<int,int>> fellOffs;

struct Coor{
	int x, y;
	Coor(int x, int y):x(x),y(y){}
};


int getNewOrientation(int current, char ins){
	if(ins == 'R') ++current;
	if(ins == 'L') --current;
	if(current>3) current = 0;
	if(current<0) current = 3;
	return current;
}

Coor getNewCoordinates(Coor c, int orientation){
	if(orientation == 0) ++c.y;
	if(orientation == 1) ++c.x;
	if(orientation == 2) --c.y;
	if(orientation == 3) --c.x;
	return c;
}

int getOrientation(char orientation){
	if(orientation == 'N') return 0;
	if(orientation == 'E') return 1;
	if(orientation == 'S') return 2;
	return 3;
}

char getOrientationLetter(int orientation){
	if(orientation == 0) return 'N';
	if(orientation == 1) return 'E';
	if(orientation == 2) return 'S';
	return 'W';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int  x, y, orientation;
	char originalOrientation;
	string ins;
	cin>>upperX>>upperY;
	while(cin>>x>>y>>originalOrientation){
		cin>>ins;
		Coor c(x, y);
		orientation = getOrientation(originalOrientation);
		bool fell = false;
		for(auto i = ins.begin(); i!=ins.end() && !fell; i++){
			if(*i == 'L' || *i == 'R'){
				orientation = getNewOrientation(orientation,*i);
			}else{
				Coor temp = getNewCoordinates(c,orientation);
				if(temp.x<0 || temp.y<0 || temp.x>upperX || temp.y>upperY){
					if(fellOffs.find(make_pair(c.x,c.y)) == fellOffs.end()){
						fellOffs.insert(make_pair(c.x, c.y));
						fell = true;
					}
				}else{
					c = temp;
				}
			}
		}
		if(fell){
			cout<<c.x<<" "<<c.y<<" "<<getOrientationLetter(orientation)<<" LOST\n";
		}else{
			cout<<c.x<<" "<<c.y<<" "<<getOrientationLetter(orientation)<<"\n";
		}
	}
	return 0;
}