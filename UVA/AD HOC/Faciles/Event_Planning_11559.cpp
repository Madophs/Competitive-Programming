#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int participants,budget,hotels,weeks;
	while(cin>>participants>>budget>>hotels>>weeks){
		int cost,beds,ans=numeric_limits<int>::max();
		while(hotels--){
			cin>>cost;
			for(int x=weeks ;x--; ){
				cin>>beds;
				if(beds>=participants && (budget-(participants*cost))>=0){
					ans=min(ans,participants*cost);
				}
			}
		}
		if(ans==numeric_limits<int>::max()){
			cout<<"stay home\n";
		}else{
			cout<<ans<<"\n";
		}
	}
    return 0;
}