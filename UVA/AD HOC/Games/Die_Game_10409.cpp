#include <bits/stdc++.h>

using namespace std;

int bottom;
vector<vector<int>> dice;

void rollNorth(){
	int temp = dice[0][1];
	for(int i = 0; i < 2; i++){
		dice[i][1] = dice[i+1][1];
	}
	dice[2][1] = bottom;
	bottom = temp;
}
void rollSouth(){
	int temp = dice[2][1];
	for(int i = 2; i > 0; i--){
		dice[i][1] = dice[i-1][1];
	}
	dice[0][1] = bottom;
	bottom = temp;
}
void rollEast(){
	int temp = dice[1][2];
	for(int i = 2; i > 0; i--){
		dice[1][i] = dice[1][i-1];
	}
	dice[1][0] = bottom;
	bottom = temp;
}
void rollWest(){
	int temp = dice[1][0];
	for(int i = 0; i < 2; i++){
		dice[1][i] = dice[1][i+1];
	}
	dice[1][2] = bottom;
	bottom = temp;
}
int getTop(){
	return dice[1][1];
}
void resetDice(){
	bottom = 6;
	dice = {
		{0,2,0},
		{3,1,4},
		{0,5,0}
	};
}
void printDice(){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			cout<<dice[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int rolls;
	string instruction;
	while(cin>>rolls && rolls){
		resetDice();
		while(rolls--){
			cin>>instruction;
			if(instruction == "north"){
				rollNorth();
			}else if(instruction == "south"){
				rollSouth();
			}else if(instruction == "west"){
				rollWest();
			}else{
				rollEast();
			}
			//cout<<instruction<<endl;
			//printDice();
		}
		cout<<getTop()<<"\n";
	}
	return 0;
}