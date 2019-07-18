#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int blocks, blockValue,previous = -1, ans = 1, tempAns = 1;
	cin>>blocks;
	while(blocks-- && cin>>blockValue){
		if(blockValue == previous)
			++tempAns;
		else
			tempAns = 1;
		previous = blockValue;
		ans = max(ans, tempAns);
	}
	cout<<ans<<"\n";
	return 0;
}
