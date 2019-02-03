#include <bits/stdc++.h>
using namespace std;

int main() {
	int l,w,h,t,c=0;
	cin>>t;
	while(t--){
		cin>>l>>w>>h;
		if(l>20 || w>20 || h>20){
			cout<<"Case "<<++c<<": bad\n";
		}else{
			cout<<"Case "<<++c<<": good\n";
		}
	}
    return 0;
}
