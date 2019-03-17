#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numRows, numCols, nonZeros,val;
	while(cin>>numRows>>numCols){
		vector<vector<int>> matrix(numRows,vector<int>(numCols,0));
		for(int row = 0; row<matrix.size(); row++){
			vector<int> indexes;
			cin>>nonZeros;
			if(!nonZeros)continue;
			while(nonZeros-- && cin>>val) indexes.emplace_back(val-1);
			for(int i = 0; i<indexes.size(); i++){
				cin>>matrix[row][indexes[i]];
			}
		}
		cout<<numCols<<" "<<numRows<<"\n";
		for(int col = 0; col<numCols; col++){
			vector< pair<int,int> > non;
			for(int row = 0; row<numRows; row++){
				if(matrix[row][col]){
					non.emplace_back(make_pair(row+1,matrix[row][col]));
				}
			}
			cout<<non.size();
			for(int i = 0; i<non.size(); i++) cout<<" "<<non[i].first;
			cout<<"\n";
			for(int i = 0; i<non.size(); i++) cout<<(i?" ":"")<<non[i].second;
			cout<<"\n";
		}
	}
	return 0;
}