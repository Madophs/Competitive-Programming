#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string help,aux = "SOS";
	int res=0;
	cin>>help;
	for(int x=0; x<help.length(); x+=3){
		for(int i=x,j=0; j<3; i++,j++){
			if(help[i]!=aux[j])++res;
		}
	}
	cout<<res<<endl;
	return 0;
}