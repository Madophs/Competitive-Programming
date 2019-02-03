#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,c=0,calls,duration,mile,juice;
	cin>>t;
	while(t--){
		cin>>calls;
		mile=juice=0;
		while(calls-- && cin>>duration){
			mile+=(duration/30+1)*10;
			juice+=(duration/60+1)*15;
		}
		if(mile==juice){
			cout<<"Case "<<++c<<": Mile Juice "<<mile<<'\n';
		}else if(mile < juice){
			cout<<"Case "<<++c<<": Mile "<<mile<<'\n';
		}else{
			cout<<"Case "<<++c<<": Juice "<<juice<<'\n';
		}
	}
	return 0;
}