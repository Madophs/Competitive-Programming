#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int menor=1e9, mayor=-1, var=0;
		while(n--){
			cin>>var;
			menor=min(menor,var);
			mayor=max(mayor,var);
		}
		cout<<((mayor-menor)*2)<<"\n";
	}
    return 0;
}
