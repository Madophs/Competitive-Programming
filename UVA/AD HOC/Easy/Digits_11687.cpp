#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string googol;
	while(cin>>googol){
		if(googol=="END")break;
		int i=1,xi=0,x0=googol.length();
		if(googol=="1"){
			cout<<"1\n";
			continue;
		}
		while(true){
			xi=to_string(x0).length();
			++i;
			if(x0==xi)break;
			x0=xi;
		}
		cout<<i<<"\n";
	}
    return 0;
}
