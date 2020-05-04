#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = (int)1e5+10;
long table[MAX_VALUE];

bool binarySearch(int l, int r) {
	int m, l_sum = 0, r_sum = 0;
	int limit = r;
	while(l < r) {
		m = (l + r) / 2;
		l_sum = table[m-1] - table[0];
		r_sum = table[limit] - table[m];
		if(l_sum == r_sum) {
			return true;
		} else {
			if(l_sum > r_sum) {
				r = m;
			} else {
				l = m+1;
			}
		}
	}
	return false;
}
	
				
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cases, n;
	table[0] = 0;
	cin >> cases;
	while(cases-- && cin >> n) {
		for(int i = 1; i <= n; ++i) {
			cin >> table[i];
			table[i] += table[i-1];
		}
		table[n+1] = table[n];
		if(binarySearch(0, n+1)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
