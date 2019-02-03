#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int l;
	string cadena;
	while(cin>>l && l){
		cin>>cadena;
		int d,r,ans=numeric_limits<int>::max();
		d=r=-1;
		for(unsigned int x=0; x<cadena.length(); x++){
			if(cadena.at(x)=='.')continue;
			if(cadena.at(x)=='Z'){
				ans=0;
				break;
			}
			if(cadena.at(x)=='R'){
				r=x;
				if(d!=-1){
					ans=min(abs(r-d),ans);
				}
			}else if (cadena.at(x)=='D'){
				d=x;
				if(r!=-1){
					ans=min(abs(r-d),ans);
				}
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}