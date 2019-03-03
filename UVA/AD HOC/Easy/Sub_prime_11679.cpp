#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int banks,debentures;
	while(cin>>banks>>debentures && (banks || debentures)){
		int money[banks+1];
		for(int x=1; x<=banks; x++)cin>>money[x];
		int debtor,creditor,debenture;
		bool possible=true;
		while(debentures--){
			cin>>debtor>>creditor>>debenture;
			money[creditor]+=debenture;
			money[debtor]-=debenture;
		}
		for(int x=1; x<=banks; x++){
			if(money[x]<0)possible=false;
		}
		cout<<(possible?"S\n":"N\n");
	}
    return 0;
}
