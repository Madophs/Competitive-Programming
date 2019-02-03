#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;
int main(){
	int n,val,caso=0;
	while(cin>>n && n){
		int ceros=0, unos=0;
		while(n--){
			cin>>val;
			if(val){
				++unos;
			}else{
				++ceros;
			}
		}
		cout<<"Case "<<++caso<<": "<<(unos-ceros)<<"\n";
	}
	return 0;
}
