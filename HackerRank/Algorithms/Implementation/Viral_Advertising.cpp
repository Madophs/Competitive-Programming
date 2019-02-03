#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, shares=5, likes=0,sum=0;
	cin>>n;	
	while(n--){
		likes = shares/2;
		sum+=likes;
		shares = likes*3;
	}
	cout<<sum<<endl;
	return 0;
}