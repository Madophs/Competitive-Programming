#include <bits/stdc++.h>

using namespace std;

int smallestPeriod(string &line){
	vector<int> z(line.length(),0);
	z[0] = -1;
	int x = 0, y = 0;
	for(int k = 1; k < line.length(); ++k){
		if(y < k){
			x = y = k;
			int index = 0;
			while(y < line.length() && line[index] == line[y]) ++index, ++y;
			z[k] = y - x;
			--y;
		}else if(y >= k && k+z[k-x] <= y){
			z[k] = z[k-x];
		}else if(y >= k && k+z[k-x] > y){
			x = k;
			int index = y - k + 1;
			++y;
			while(y < line.length() && line[index] == line[y]) ++index, ++y;
			z[k] = y - x;
			--y;
		}
		if(z[k] && k + z[k] == line.length() && (int)line.length() % k == 0){
			return k;
		}
	}
	return (int)line.length();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string line;
	cin>>t;
	while(t-- && cin>>line){
		cout<<smallestPeriod(line)<<"\n";
		if(t) cout<<"\n";
	}
	return 0;
}
