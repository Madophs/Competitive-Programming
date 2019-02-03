#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,m,x,y;
	while(cin>>t && t){
		cin>>n>>m;
		while(t--){
			cin>>x>>y;
			if(x==n || y==m){
				cout<<"divisa\n";
			}else if(x<n && y>m){
				cout<<"NO\n";
			}else if(x>n && y>m){
				cout<<"NE\n";
			}else if(x>n && y<m){
				cout<<"SE\n";
			}else{
				cout<<"SO\n";
			}
		}
	}
    return 0;
}