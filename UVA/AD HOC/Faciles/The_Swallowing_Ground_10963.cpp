#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, col, i,j;
	bool jump = false;
	cin>>t;
	while(t-- && cin>>col){
		if(jump)cout<<'\n';
		jump = true;
		int diff = -1;
		bool possible = true;
		for(int x=0; x<col; x++){
			cin>>i>>j;
			if(diff==-1){
				diff = abs(i-j);
			}else{
				if(diff!=abs(i-j)) possible = false;
			}
		}
		cout<<(possible?"yes\n":"no\n");
	}
	return 0;
}