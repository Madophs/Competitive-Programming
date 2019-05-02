#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> table;
struct Coor{
	int row, col;
	Coor(int row, int col){
		this->row = row;
		this->col = col;
	}
};

Coor findBlock(int block){
	for(int i = 0; i<table.size(); i++){
		for(int j = 0; j<table[i].size(); j++){
			if(table[i][j] == block) return Coor(i,j);
		}
	}
	return Coor(-1,-1);
}

void printTable(){
	for(int i = 0; i<table.size(); i++){
		cout<<i<<":";
		for(int j = 0; j<table[i].size(); j++){
			cout<<" "<<table[i][j];
		}
		cout<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int blocks;
	cin>>blocks;
	for(int i = 0; i<blocks; i++) table.emplace_back(vector<int>(1,i));
	int blockA, blockB;
	string ins, action;
	while(cin>>ins && ins!="quit" && cin>>blockA>>action>>blockB){
		if(blockA == blockB) continue;
		if(blockA >= table.size() || blockB >= table.size()) continue;
		if(blockA < 0 || blockB < 0) continue;
		Coor c1 = findBlock(blockA);
		Coor c2 = findBlock(blockB);
		if(c1.row == c2.row) continue;
		if(ins == "move"){
			table[c1.row].erase(table[c1.row].begin()+c1.col);
			while(c1.col < table[c1.row].size()){
				table[table[c1.row][c1.col]].emplace_back(table[c1.row][c1.col]);
				table[c1.row].erase(table[c1.row].begin()+c1.col);
			}
			if(action == "onto"){
				while(c2.col+1 < table[c2.row].size()){
					table[table[c2.row][c2.col+1]].emplace_back(table[c2.row][c2.col+1]);
					table[c2.row].erase(table[c2.row].begin()+(c2.col+1));
				}
				table[c2.row].emplace_back(blockA);
			}else{
				table[c2.row].emplace_back(blockA);
			}
		}else{
			vector<int> pile;
			if(action == "onto"){
				while(c1.col < table[c1.row].size()){
					pile.emplace_back(table[c1.row][c1.col]);
					table[c1.row].erase(table[c1.row].begin()+c1.col);
				}
				while(c2.col+1 < table[c2.row].size()){
					table[table[c2.row][c2.col+1]].emplace_back(table[c2.row][c2.col+1]);
					table[c2.row].erase(table[c2.row].begin()+(c2.col+1));
				}
				for(int stock: pile){
					table[c2.row].emplace_back(stock);
				}
			}else{
				while(c1.col < table[c1.row].size()){
					pile.emplace_back(table[c1.row][c1.col]);
					table[c1.row].erase(table[c1.row].begin()+c1.col);
				}
				int i;
				for(i = 0; i<pile.size(); i++) table[c2.row].emplace_back(-1);
				i = table[c2.row].size()-1;
				for(int j = pile.size()-1; j>=0; j--){
					table[c2.row][i--] = pile[j];
				}
			}
		}
	}
	printTable();
	return 0;
}
