#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,val;
	auto  formula = [](int n){
				long long res = (((((n*567)/9)+7492)*235)/47)-498;
				string cadena = std::to_string(res);
				return cadena.at(cadena.length()-2)-'0';
			};
	cin>>t;
	while(t--){
		cin>>val;
		cout<<formula(val)<<"\n";
	}
    return 0;
}
