#include <bits/stdc++.h>

using namespace std;

enum Direction{
	x_positive, x_negative, y_positive, y_negative, z_positive, z_negative 
};

Direction getNewDirection(Direction direction, string ins){
	switch(direction){
		case x_positive:
			if(ins == "+y") return y_positive;
			if(ins == "-y") return y_negative;
			if(ins == "+z") return z_positive;
			if(ins == "-z") return z_negative;
		break;
		case x_negative:
			if(ins == "+y") return y_negative;
			if(ins == "-y") return y_positive;
			if(ins == "+z") return z_negative;
			if(ins == "-z") return z_positive;
		break;
		case y_positive:
			if(ins == "+y") return x_negative;
			if(ins == "-y") return x_positive;
			if(ins == "+z") return y_positive;
			if(ins == "-z") return y_positive;
		break;
		case y_negative:
			if(ins == "+y") return x_positive;
			if(ins == "-y") return x_negative;
			if(ins == "+z") return y_negative;
			if(ins == "-z") return y_negative;
		break;
		case z_positive:
			if(ins == "+y") return direction;
			if(ins == "-y") return direction;
			if(ins == "+z") return x_negative;
			if(ins == "-z") return x_positive;
		break;
		case z_negative:
			if(ins == "+y") return direction;
			if(ins == "-y") return direction;
			if(ins == "+z") return x_positive;
			if(ins == "-z") return x_negative;
		break;
	}
	return direction;
}

string getCurrentDirection(Direction direction){
	if(direction == x_positive) return "+x";
	if(direction == x_negative) return "-x";
	if(direction == y_positive) return "+y";
	if(direction == y_negative) return "-y";
	if(direction == z_positive) return "+z";
	return "-z";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length;
	string ins;
	Direction currentDirection = x_positive;
	while(cin>>length && length--){
		currentDirection = x_positive;
		while(length-- && cin>>ins){
			if(ins == "No") continue;
			currentDirection = getNewDirection(currentDirection, ins);
		}
		cout<<getCurrentDirection(currentDirection)<<"\n";
	}
	return 0;
}