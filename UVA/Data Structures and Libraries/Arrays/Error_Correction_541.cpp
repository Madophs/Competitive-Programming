#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dimension, val;
	while(cin>>dimension && dimension){
		int sumCol[dimension], sumRow[dimension];
		memset(sumCol,0,sizeof sumCol);
		memset(sumRow,0,sizeof sumRow);
		for(int row = 0; row<dimension; row++){
			for(int col = 0; col<dimension; col++){
				cin>>val;
				if(val) ++sumRow[row], ++sumCol[col];
			}
		}
		bool correct = true;
		vector< pair<int,int> > colOdds, rowOdds;
		for(int i = 0; i<dimension; i++){
			if(sumRow[i]&1){
				correct = false;
				rowOdds.push_back(make_pair(sumRow[i],i+1));
			}
			if(sumCol[i]&1){
				correct = false;
				colOdds.push_back(make_pair(sumCol[i],i+1));
			}
		}
		if(correct){
			cout<<"OK\n";
		}else{
			if(rowOdds.size() == 1 && colOdds.size() == 1){
				cout<<"Change bit ("<<rowOdds[0].second<<","<<colOdds[0].second<<")\n";
			}else{
				cout<<"Corrupt\n";
			}
		}
	}	
	return 0;
}