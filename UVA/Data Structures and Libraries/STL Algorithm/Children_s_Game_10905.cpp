#include <bits/stdc++.h>

using namespace std;

bool mdsSort(string x, string y){
	string a = x+y, b = y+x;
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string val;
	while(cin>>n && n){
		vector<string> numbers;
		while(n-- && cin>>val) numbers.emplace_back(val);
		sort(numbers.begin(), numbers.end(),mdsSort);
		for(int i = 0; i<numbers.size(); i++){
			cout<<numbers[i];
		}
		cout<<"\n";
	}
	return 0;
}
