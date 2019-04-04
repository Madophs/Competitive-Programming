#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, money, numGarments, garmentsAvailable, ans;
	int garments[22][22];
	bool memo[2][205];
	cin>>test;
	while(test-- && cin>>money>>garmentsAvailable){
		for(int i = 0; i < garmentsAvailable; i++){
			cin>>garments[i][0];
			for(int g = 1; g <= garments[i][0]; g++) cin>>garments[i][g];
		}
		memset(memo, false, sizeof memo);
		for(int i = 1; i <= garments[0][0]; i++){
			int dif = money-garments[0][i];
			if(dif>-1) memo[0][dif] = true;
		}
		bool turn = false;
		for(int g = 1; g<garmentsAvailable; g++){
			for(int m = 0; m <= money; m++){
				if(memo[(int)turn][m]){
					for(int i = 1; i<=garments[g][0]; i++){
						int dif = m - garments[g][i];
						if(dif > -1) memo[(int)!turn][dif] = true;
					}
				}
				memo[turn][m] = false;
			}
			turn=!turn;
		}
		for(ans = 0; ans <= money && !memo[turn][ans]; ans++);
		if(ans == money+1){
			cout<<"no solution\n";
		}else{
			cout<<(money-ans)<<"\n";
		}
	}	
	return 0;
}