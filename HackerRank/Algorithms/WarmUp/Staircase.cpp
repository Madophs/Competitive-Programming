#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int dim;cin>>dim;
	for(int x=dim-1; x>=0; x--){
		string cad(x,' ');
		cout<<setw(dim)<<setfill('#')<<left<<cad<<"\n";
	}
	return 0;
}