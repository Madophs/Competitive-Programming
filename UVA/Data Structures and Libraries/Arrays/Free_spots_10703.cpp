#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w,h,n, x1,y1,x2,y2;
	bool matrix[505][505];
	while(cin>>w>>h>>n && (w || h || n)){
		memset(matrix,true,sizeof matrix);
		while(n-- && cin>>x1>>y1>>x2>>y2){
			for(int i = min(y1,y2)-1; i<max(y1,y2); i++){
				for(int j = min(x1,x2)-1; j<max(x1,x2); j++){
					matrix[i][j] = false;
				}
			}
		}
		int ans = 0;
		for(int row = 0; row<h; row++){
			for(int col = 0; col<w; col++){
				ans+=matrix[row][col];
			}
		}
		if(!ans){
			cout<<"There is no empty spots.\n";
		}else if(ans == 1){
			cout<<"There is one empty spot.\n";
		}else{
			cout<<"There are "<<ans<<" empty spots.\n";
		}
	}	
	return 0;
}