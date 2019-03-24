#include <bits/stdc++.h>

using namespace std;

int nextPosition(int pos){
	if(pos<9) return pos;
	return pos%9;
}

string charValue(int val){
	if(val == 0) return "B";
	if(val == 1) return "G";
	return "C";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int bins[9];
	int values[3][3];
	while(cin>>bins[0]){
		for(int x = 1; x<9 && cin>>bins[x]; x++);
		for(int row = 0; row<3; row++){
			for(int col = 0; col<3; col++){
				values[row][col] = bins[nextPosition(row*3+3+col)] + bins[nextPosition(row*3+6+col)];
			}
		}
		vector<string> orderedBins;
		long long minimum = numeric_limits<long long>::max();
		for(int x = 0; x<3; x++){
			for(int y = 0; y<3; y++){
				if(y == x) continue;
				for(int w = 0; w<3; w++){
					if(w == y || w == x) continue;
					int sum = values[0][x] + values[1][y] + values[2][w];
					if(minimum >= sum){
						if(minimum > sum){
							minimum = sum;
							orderedBins.clear();
							orderedBins.push_back(charValue(x)+charValue(y)+charValue(w));
						}else{
							orderedBins.push_back(charValue(x)+charValue(y)+charValue(w));
						}
					}
				}
			}
		}
		sort(orderedBins.begin(), orderedBins.end());
		cout<<orderedBins[0]<<" "<<minimum<<"\n";
	}
	return 0;
}