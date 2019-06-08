#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int streets, integers, tests = 0;
	while(cin>>streets>>integers && (streets || integers)){
		if(integers*27<streets){
			cout<<"Case "<<++tests<<": impossible\n";
		}else{
			double ans = ceil((double)(streets)/(double)(integers))-1;
			cout<<"Case "<<++tests<<": "<<(int)ans<<"\n";
		}
	}
	return 0;
}