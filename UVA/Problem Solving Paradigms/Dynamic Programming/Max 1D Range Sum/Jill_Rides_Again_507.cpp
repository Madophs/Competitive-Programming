#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numRoutes, busStops, niceness;
	cin>>numRoutes;
	for(int route = 1; route <= numRoutes; route++){
		cin>>busStops;
		--busStops;
		int ans = 0,  current = 0, sum = 0, x = -1, dif = 0, difAux = 0, i = -1, j = -1;
		while(busStops-- && cin>>niceness){
			sum+=niceness;
			++current;
			if(sum > 0){
				if(x == -1)x = current;
				difAux = max(difAux, current+1-x);
			}
			if(sum >= ans){
				if(sum > ans){
					if(i != x) i = x;
					j = current + 1;
				}else{
					if(difAux > dif){
						i = x, j = current + 1;
					}
				}
				dif = max(dif, j-i), ans = sum;
			}
			if(sum < 0){
				sum = 0, x = -1, difAux = 0;
			}
		}
		if(ans>0){
			cout<<"The nicest part of route "<<route<<" is between stops "<<i<<" and "<<j<<"\n";
		}else{
			cout<<"Route "<<route<<" has no nice parts\n";
		}
	}
	return 0;
}