#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> lines;
	string line;
	int maxLineLength = 0;
	while(getline(cin,line)){
		lines.emplace_back(line);
		maxLineLength = max(maxLineLength,(int) line.length());
	}
	for(int col = 0; col < maxLineLength; ++col){
		for(int row = lines.size()-1; row >= 0; --row){
			if(col >= lines[row].length()){
				cout<<" ";
			}else{
				cout<<lines[row][col];
			}
		}
		cout<<"\n";
	}
	return 0;
}
