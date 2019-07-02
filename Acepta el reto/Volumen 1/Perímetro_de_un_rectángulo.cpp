#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, perimetro;
	while(cin>>x>>y && (x > -1 && y > -1)){
		perimetro = (x<<1) + (y<<1);
		cout<<perimetro<<"\n";
	}	
	return 0;
}
