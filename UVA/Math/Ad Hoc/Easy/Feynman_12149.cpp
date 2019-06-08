#include <bits/stdc++.h>

using namespace std;

vector<long long> squares;
void initSquares(){
	for(long long i = 0; i<=101; i++){
		squares.emplace_back(i*i);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	long long ans;
	initSquares();
	while(cin>>num && num){
		ans = 0;
		for(int i = 0; i<=num; i++){
			ans += squares[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}