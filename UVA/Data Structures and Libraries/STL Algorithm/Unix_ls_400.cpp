#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	files;
	string fileName, dashes(60,'-');
	while(cin>>files){
		cout<<dashes<<'\n';
		vector<string> sortedFiles;
		int maxLength = 0;
		while(files-- && cin>>fileName){
			sortedFiles.push_back(fileName);
			maxLength = max(maxLength, (int)fileName.length());
		}
		sort(sortedFiles.begin(), sortedFiles.end());
		int cols = ((60-maxLength)/(maxLength+2))+1, rows = ceil((double)sortedFiles.size()/(double)cols), i = 0;
		vector< vector<string> > matrix(rows, vector<string>(cols,""));
		for(int col = 0; col<cols && i<sortedFiles.size(); col++){
			for(int row = 0; row<rows && i<sortedFiles.size(); row++){
				matrix[row][col] = sortedFiles[i++];
			}
		}
		for(int row = 0; row<rows; row++){
			cout<<fixed<<setw(60);
			for(int col = 0; col<cols; col++){
				if(matrix[row][col].empty()){
					continue;
				}
				if(col+1 == cols || (col+1 < cols && matrix[row][col+1].empty())){
					cout<<fixed<<setw(maxLength)<<left;
				}else{
					cout<<fixed<<setw(maxLength+2)<<left;
				}
				cout<<matrix[row][col];
				
			}
			cout<<'\n';
		}
	}
	return 0;
}