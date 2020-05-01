#include <bits/stdc++.h>

using namespace std;

void sortAllRows(vector<string> &vec) {
	for(int row = 0; row < vec.size(); ++row) {
		sort(vec[row].begin(), vec[row].end());
	}
}
bool allColsSorted(vector<string> &vec) {
	sortAllRows(vec);
	for(int col = 0; col < (int) vec.size(); ++col) {
		for(int row = 1; row < (int) vec.size(); ++row) {
			if(vec[row][col] < vec[row-1][col]) return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cases, rows;
	vector<string> grid;
	string line;
	cin >> cases;
	while(cases --) {
		cin >> rows;
		while(rows--) {
			cin >> line;
			grid.emplace_back(line);
		}
		if(allColsSorted(grid))
			cout << "YES\n";
		else 
			cout << "NO\n";
		grid.clear();
	}
	return 0;
}
