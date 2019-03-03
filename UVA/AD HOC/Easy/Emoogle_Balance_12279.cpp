#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,var,c=0;
	while(cin>>n && n){
		int cont=0;
		++c;
		while(n--){
			cin>>var;
			cont=(var==0)?cont-1:cont+1;
		}
		cout<<"Case "<<c<<": "<<cont<<"\n";
	}
	return 0;
}
