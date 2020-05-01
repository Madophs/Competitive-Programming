#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for(int &val : A) cin >> val;
	for(int &val : B) cin >> val;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = 0, j = 0;
	int matches = 0;
	while(i < n && j < n) {
		if(A[i] == B[j]) {
			++i, ++j;
			++matches;
		} else {
			if(A[i] < B[j]) {
				++i;
			} else {
				++j;
			}
		}
	}
	if(matches == n) {
		cout << (n-1) << "\n";
	} else {
		cout << (matches+1) << "\n";
	}
	return 0;
}
