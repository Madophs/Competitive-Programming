#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length, val, ans, sum;
	while(cin>>length && length){
		ans = sum = 0;
		while(length-- && cin>>val){
			sum += val;
			ans = max(ans,sum);
			if(sum < 0) sum = 0;
		}
		if(ans > 0){
			cout<<"The maximum winning streak is "<<ans<<".\n";
		}else{
			cout<<"Losing streak.\n";
		}
	}
	return 0;
}