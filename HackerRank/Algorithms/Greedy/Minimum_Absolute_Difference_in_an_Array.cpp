#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	cin>>size;
	vector<int> numbers(size);
	while(size-- && cin>>numbers[size]);
	sort(numbers.begin(), numbers.end());
	int ans = (int) 1e9;
	for(int i = 0; i<numbers.size()-1; i++) ans = min(ans, abs(numbers[i]-numbers[i+1]));
	cout<<ans<<"\n";
	return 0;
}