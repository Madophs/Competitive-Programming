#include <bits/stdc++.h>
#define EPSILON 1e-9

using namespace std;

double log2(double n){
	return log10(n)/log10(2);
}

double test(double pay, int months, double price, double interest){
	for(int i = 0; i<months; i++){
		price = (price*interest)-pay;
	}
	return price;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(3);
	int originalPrice = 1000, months = 2, interest = 10;
	double a = 1e-3, b = (1.0+(interest/100.0))*originalPrice, d = 0.0;
	cout<<"Bisection Method discussed in Competitive Programming 3\n";
	cout<<"Lowers Limit = "<<a<<", Upper Limit = "<<b<<endl;
	for(int i = 0; i<log2((b-a)/EPSILON); i++){
		d = (a+b)/2.0;
		double res = test(d,months,(double)originalPrice, (1.0+(interest/100.0)));
		cout<<a<<" "<<b<<" "<<d<<" "<<res<<endl;
		if(res>EPSILON){
			a = d;
		}else{
			b = d;
		}
	}
	cout<<"Final answer = "<<d<<endl;
	return 0;
}