#include <bits/stdc++.h>

using namespace std;

int division = 1000;

int moneyGained(double x, double y, double z){
	z*=division;
	if(x/2.0 >= y) return z/division;
	if(y/2.0 >= x) return 0;
	int ans = 0,hour = ceil(z/(x+y));
	if(x >= y){
		ans = (y*hour) + ((x-y)*2*hour);
	}else{
		ans = (x*hour) - ((y-x)*hour);
	}
	z/=division;
	ans/=division;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, hoursA, hoursB, money;
	cin>>tests;
	while(tests-- && cin>>hoursA>>hoursB>>money){
		cout<<moneyGained(hoursA, hoursB,money)<<"\n";
	}
	return 0;
}
