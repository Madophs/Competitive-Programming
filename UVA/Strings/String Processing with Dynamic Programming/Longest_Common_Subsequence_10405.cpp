#include <bits/stdc++.h>

using namespace std;

string line1, line2;
const int matchScore = 1, mismatchScore = 0, insertScore = 0, deleteScore = 0;
int matrix[1005][1005];

int lcs(){
	int op1, op2, op3;
	for(int i = 0; i <= line1.length(); ++i){
		for(int j = 0; j <= line2.length(); ++j){
			if(!i && !j){
				matrix[i][j] = 0;
			}else if(!i || !j){
				matrix[i][j] = (!i ? j : i) * mismatchScore;
			}else{
				op1 = matrix[i-1][j-1] + (line1[i-1] == line2[j-1] ? matchScore : mismatchScore);
				op2 = matrix[i-1][j] + deleteScore;
				op3 = matrix[i][j-1] + insertScore;
				matrix[i][j] = max(op1, max(op2, op3));
			}
		}		
	}
	return matrix[line1.length()][line2.length()];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(getline(cin, line1) && getline(cin, line2)){
		cout<<lcs()<<"\n";
	}
	return 0;
}
