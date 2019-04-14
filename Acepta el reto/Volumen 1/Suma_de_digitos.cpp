#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string numero, ans;
	int suma;
	while(cin>>numero && numero[0]!='-'){
		ans = "";
		suma = 0;
		for(int i = 0; i<numero.length(); i++){
			suma += numero[i]-'0';
			ans += numero[i];
			if(numero.length()>1 && i+1 < numero.length()) ans += " + ";
		}
		cout<<ans<<" = "<<suma<<"\n";
	}
	return 0;
}