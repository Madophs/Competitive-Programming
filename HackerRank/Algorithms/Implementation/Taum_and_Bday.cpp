#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,whites, blacks, whiteCost,blackCost,paint;
	cin>>t;
	while(t-- && cin>>blacks>>whites>>blackCost>>whiteCost>>paint){
		long long min_a = blackCost <= whiteCost+paint ? blackCost : whiteCost+paint;
		long long min_b = whiteCost <= blackCost+paint ? whiteCost : blackCost+paint;
		long long ans = whites * min_b + blacks * min_a;
		cout<<ans<<endl;
	}
	return 0;
}