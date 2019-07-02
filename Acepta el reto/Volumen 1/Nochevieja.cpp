#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string tiempo;
	int hora, minuto, falta;
	while(cin>>tiempo){
		if(tiempo == "00:00") break;
		hora = atoi(tiempo.substr(0,2).c_str());
		minuto = atoi(tiempo.substr(3,2).c_str());
		falta = (24-hora) * 60 - minuto;
		cout<<falta<<"\n";
	}
	return 0;
}
