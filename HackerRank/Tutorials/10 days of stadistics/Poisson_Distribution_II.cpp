#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	double costA,costB;
	cin>>costA>>costB;
	cout<<setprecision(3)<<fixed<<160.0+40.0*(costA+pow(costA,2))<<endl;
	cout<<setprecision(3)<<fixed<<128.0+40.0*(costB+pow(costB,2))<<endl;
	return 0;
}