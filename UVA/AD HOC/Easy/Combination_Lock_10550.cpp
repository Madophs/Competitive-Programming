#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c,d;
	while(cin>>a>>b>>c>>d && (a || b || c || d)){
		int res=1080;
		if(a!=b)
			res+=a>b? (a-b)*9:((40-b)+a)*9;
		if(b>c){
			int aux = abs(40-b);
			res+=(c+aux)*9;
		}else if (b!=c){
			res+=abs(b-c)*9;
		}
		if(c!=d)
			res+=c>d?(c-d)*9:((40-d)+c)*9;
		cout<<res<<"\n";
	}
    return 0;
}