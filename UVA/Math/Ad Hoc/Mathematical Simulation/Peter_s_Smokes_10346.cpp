#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	while(cin>>n>>k){
		int butts = 0, cigarrettes = 0;;
		do{
			cigarrettes += n;
			n += butts;
			butts = n%k;
			n/=k;
		}while(n);
		cout<<cigarrettes<<"\n";
	}
	return 0;
}
