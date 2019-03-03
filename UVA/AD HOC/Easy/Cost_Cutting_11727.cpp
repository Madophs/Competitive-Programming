#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, c=0,caso=0;
	vector<int> vec(3,0);
	cin>>t;
	while(t--){
		c=3;
		while(c--)cin>>vec[c];
		sort(vec.begin(), vec.end());
		cout<<"Case "<<++caso<<": "<<vec[1]<<"\n";
	}
    return 0;
}
