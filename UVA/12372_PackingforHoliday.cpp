#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;

int main(){
	int tc,caso=0;;
	cin>>tc;
	while(tc--){
		int w,h,l;
		bool cierto=true;
		cin>>l>>w>>h;
		if(l>20 || w>20 || h>20)cierto=false;
		cout<<"Case "<<++caso<<": "<<(cierto?"good\n":"bad\n");
	}
	return 0;
}
