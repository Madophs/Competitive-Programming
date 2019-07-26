#include <bits/stdc++.h>

using namespace std;

int matrix[85][85];
const int matchScore = 0, mismatchScore = 1;
string str1, str2;

int score(char a, char b){
	if(a == b) return matchScore;
	return mismatchScore;
}

void needlemanWunsch(){
	int op1, op2, op3;
	for(int i = 0; i <= str1.length(); ++i){
		for(int j = 0; j <= str2.length(); ++j){
			if(!i && !j){
				matrix[i][j] = 0;
			}else if(!i || !j){
				matrix[i][j] = (!i ? j : i) * mismatchScore;
			}else{
				op1 = matrix[i-1][j-1] + score(str1[i-1], str2[j-1]);
				op2 = matrix[i-1][j] + score(str1[i-1], '_');
				op3 = matrix[i][j-1] + score('_', str2[j-1]);
				matrix[i][j] = min(op1, min(op2, op3));	
			}
		}
	}
	string newString = "";
	vector<pair<string, char>> transforms;
	int row = str1.length(), col = str2.length(), currScore = 0;
	while(row > 0  || col > 0){
		op1 = matrix[row-1][col-1] + score(str1[row-1], str2[col-1]);
		op2 = matrix[row-1][col] + score(str1[row-1], '_');	
		op3 = matrix[row][col-1] + score('_', str2[col-1]);
		currScore = matrix[row][col];
		if(row > 0 && col > 0 && currScore == op1){
			if(matrix[row-1][col-1] != op1-1){
				newString = str1[row-1] + newString;
				transforms.emplace_back(make_pair("Match",'-'));
			}else{
				newString = str2[col-1] + newString;
				transforms.emplace_back(make_pair("Replace",str2[col-1]));
			}
			--row,--col;
		}else if(row > 0 && currScore == op2){
			transforms.emplace_back(make_pair("Delete",'-'));
			--row;
		}else{
			newString = str2[col-1] + newString;
			transforms.emplace_back(make_pair("Insert",str2[col-1]));
			--col;
		}
	}
	cout<<matrix[str1.length()][str2.length()]<<endl;
	int index = 0;
	for(int i = transforms.size()-1, num = 0; i > -1; --i){
		++index;
		if(transforms[i].first == "Delete"){
			cout<<++num<<" Delete "<<index<<"\n";
			--index;
		}else if(transforms[i].first == "Insert"){
			cout<<++num<<" Insert "<<index<<","<<transforms[i].second<<"\n";
		}else if(transforms[i].first == "Replace"){
			cout<<++num<<" Replace "<<index<<","<<transforms[i].second<<"\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool blackLine = false;
	while(getline(cin,str1) && getline(cin,str2)){
		if(blackLine) cout<<"\n";
		else blackLine = true;
		needlemanWunsch();
	}	
	return 0;
}
