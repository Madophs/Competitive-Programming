#include <bits/stdc++.h>

using namespace std;

int gcd(int i, int j){
	return j == 0 ? i : gcd(j, i % j);
}

int getValueOfG(int number){
	int g = 0;
	for(int i=1;i<number;i++){
		for(int j=i+1;j<=number;j++){
			g+=gcd(i,j);
		}
	}
	return g;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number;
	while(cin>>number && number){
		cout<<getValueOfG(number)<<"\n";
	}
	return 0;
}
