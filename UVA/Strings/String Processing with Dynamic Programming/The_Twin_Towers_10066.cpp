#include <bits/stdc++.h>

using namespace std;

int matrix[105][105];
vector<int> tower1, tower2;

void maxHeight(){
	int matchCost;
	for(int i = 0; i <= tower1.size(); ++i){
		for(int j = 0; j <= tower2.size(); ++j){
			if(!i || !j){
				matrix[i][j] = 0;
			}else{
				matchCost = matrix[i-1][j-1] + (tower1[i-1] == tower2[j-1]);	
				matrix[i][j] = max(matchCost, max(matrix[i-1][j], matrix[i][j-1]));	
			}
		}
	}
	cout<<matrix[(int)tower1.size()][(int)tower2.size()]<<"\n\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tower1Blocks, tower2Blocks, linenumber = 0;
	while(cin>>tower1Blocks>>tower2Blocks && (tower1Blocks || tower2Blocks) && ++linenumber){

		tower1.resize(tower1Blocks), tower2.resize(tower2Blocks);
		while(tower1Blocks-- && cin>>tower1[tower1Blocks]);
		while(tower2Blocks-- && cin>>tower2[tower2Blocks]);
		cout<<"Twin Towers #"<<linenumber<<"\n";
		cout<<"Number of Tiles : ";
		maxHeight();
	}
	return 0;
}
