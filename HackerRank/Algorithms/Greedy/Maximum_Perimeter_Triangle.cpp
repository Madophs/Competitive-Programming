#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long n;
	cin >> n;
	vector<long> sides(n);
	for(auto &val: sides) cin >> val;
	sort(sides.begin(), sides.end());
	long a = 0, b = 0, c = 0, max_area = -1;
	for(long i = 2; i < sides.size(); ++i) {
		if(sides[i-1] + sides[i-2] <= sides[i]) continue;
		long temp_area = sides[i] + sides[i-1] + sides[i-2];
		if(max_area <= temp_area) {
			if(max_area == temp_area) {
				if(c < sides[i] || (c == sides[i] && a < sides[i-2])) {
					c = sides[i];
					b = sides[i-1];
					a = sides[i-2];
				}
			} else {
					c = sides[i];
					b = sides[i-1];
					a = sides[i-2];
			}
			max_area = temp_area;
		}
	}
	if(max_area != -1) {
		cout << a << " " << b << " " << c << "\n";
	} else {
		cout << -1 << "\n";
	}
	return 0;
}
