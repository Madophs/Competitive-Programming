#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	cin>>size;
	vector<int> calories(size);
	while(size-- && cin>>calories[size]);
	sort(calories.begin(), calories.end(), greater<int>());
	long long ans = 0;
	for(int i = 0; i<calories.size(); i++) ans += (1LL<<i)*(long long)calories[i];
	cout<<ans<<"\n";
	return 0;
}