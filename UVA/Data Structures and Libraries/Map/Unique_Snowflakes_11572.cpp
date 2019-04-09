#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, numSnowflakes,snowflake, ans, uniqueness;
	unordered_map<int,int> uniques;
	cin>>tests;
	while(tests-- && cin>>numSnowflakes){
		int prevIndex = -1, currentIndex;
		uniqueness = ans = 0;
		uniques.clear();
		for(int i = 0; i<numSnowflakes && cin>>snowflake; i++){
			if(uniques.find(snowflake) == uniques.end()){
				uniques[snowflake] = i;
				++uniqueness;
			}else{
				currentIndex = uniques.find(snowflake)->second;
				if(currentIndex > prevIndex){
					prevIndex = currentIndex;
					uniqueness = i - currentIndex;
				}else{
					++uniqueness;
				}
				uniques[snowflake] = i;
			}
			ans = max(ans,uniqueness);
		}
		cout<<ans<<"\n";
	}
	return 0;
}