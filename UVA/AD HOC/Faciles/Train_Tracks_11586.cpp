#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, females, males, numPieces;
	string pieces;
	cin>>t;
	cin.ignore();
	while(t--){
		getline(cin,pieces);
		females = males = numPieces = 0;
		for(auto it = pieces.begin(); it!=pieces.end(); it++){
			if(*it == ' ') continue;
			++numPieces;
			if(*it == 'F'){
				++females;
			}else{
				++males;
			}
		}
		numPieces>>=1;
		cout<<(females==males && numPieces>1?"LOOP\n":"NO LOOP\n");
	}
	return 0;
}