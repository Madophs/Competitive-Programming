#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	double r,pi=3.14;
	cin>>t;
	while(t-- && cin>>r){
		double outside = pi*pow(r,2);
		double triangle = 0.25*3.0*1.73*pow(r,2.0);
		double side=sqrt((4.0*triangle)/1.73);
		double secondRadio = side/(2.0*1.73);
		double secondArea = pi*pow(secondRadio,2.0);
		double ans = (triangle-secondArea);
		//side/=3.0;
		cout<<outside<<endl;
		cout<<triangle<<endl;
		cout<<side<<endl;
		cout<<secondRadio<<endl;
		cout<<secondArea<<endl;
		cout<<ans<<endl;
	}
	return 0;
}