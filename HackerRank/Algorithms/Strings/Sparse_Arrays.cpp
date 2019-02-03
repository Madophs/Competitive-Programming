#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin>>n;
	string words[n];
	for(int x=0; x<n; x++)cin>>words[x];
	cin>>q;
	string kmp[q];
	for(int x=0; x<q; x++)cin>>kmp[x];
	for(int x=0; x<q; x++){
		int cont = 0;
		for(int y=0; y<n; y++){
			cont += kmp[x]==words[y];
		}
		cout<<cont<<endl;
	}
	return 0;
}