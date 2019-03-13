#include <bits/stdc++.h>

using namespace std;

void rotate(vector<string> &vec){
	vector<string> temp;
	for(int col = 0; col<vec[0].length(); col++){
		string line = "";
		for(int row = vec.size()-1; row>=0; row--){
			line+=vec[row][col];
		}
		temp.push_back(line);
	}
	vec = temp;
}

int countOcurrences(vector<string> &big, vector<string> &small){
	int cont = 0;
	for(int row = 0; row<(big.size()-small.size())+1; row++){
		for(int col = 0; col<(big[0].size()-small[0].length())+1; col++){
			bool same = true;
			for(int i = 0; i<small.size() && same; i++){
				for(int j = 0; j<small[0].length() && same; j++){
					same = small[i][j] == big[i+row][j+col];
				}
			}
			cont += same;
		}
	}
	return cont;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int big,small;
	string line;
	while(cin>>big>>small && (big && small)){
		vector<string> bigSquare, smallSquare;
		while(big-- && cin>>line) bigSquare.push_back(line);
		while(small-- && cin>>line) smallSquare.push_back(line);
		int a = countOcurrences(bigSquare,smallSquare);
		rotate(smallSquare);
		int b = countOcurrences(bigSquare,smallSquare);
		rotate(smallSquare);
		int c = countOcurrences(bigSquare,smallSquare);
		rotate(smallSquare);
		int d = countOcurrences(bigSquare,smallSquare);
		rotate(smallSquare);
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}
	return 0;
}