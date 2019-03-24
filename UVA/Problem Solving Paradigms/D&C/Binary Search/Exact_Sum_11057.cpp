#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int books,money,price;
	while(cin>>books){
		vector<int> prices;
		for(;books--;){
			cin>>price;
			prices.push_back(price);
		}
		cin>>money;
		sort(prices.begin(),prices.end());
		pair<int,int> result;
		int dif=1e9;
		for(auto x = prices.begin(); x!=prices.end() && *x<money; x++){
			for(auto y = x+1; y!=prices.end() && (*x+*y<=money); y++){
				if((*x)+(*y)==money){
					int auxDif = abs((*x)-(*y));
					if(auxDif<dif){
						result.first=min(*x,*y);
						result.second=max(*x,*y);
					}
				}
			}
		}
		cout<<"Peter should buy books whose prices are "<<result.first<<" and "<<result.second<<".\n\n";
	}
    return 0;
}