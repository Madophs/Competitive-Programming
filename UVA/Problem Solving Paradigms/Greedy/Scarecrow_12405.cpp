#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	int tests, size, ans, i;
	cin>>tests;
	for(int t = 1; t<=tests; t++){
		cin>>size;
		cin>>line;
		ans = i = 0;
		while(i<size){
			if(line[i] == '.'){
				++ans, i+=3;
			}else{
				++i;
			}
		}
		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
	return 0;
}