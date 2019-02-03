#include <bits/stdc++.h>

using namespace std;

int main() {
	double cows,cars,show;
	while(cin>>cows>>cars>>show){
		double pro1=0.0,pro2=0.0;
		pro1=(cows/(cows+cars))*(cars/(cows+cars-show-1));
		pro2=(cars/(cows+cars))*((cars-1)/(cars+cows-show-1));
		cout<<fixed<<setprecision(5)<<(pro1+pro2)<<"\n";
	}
	return 0;
}
