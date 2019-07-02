#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int casos;
	long long aquarios, capacidad, diferencia, res;
	cin>>casos;
	while(casos-- && cin>>aquarios>>capacidad>>diferencia){
		--aquarios;
		res = (aquarios+1LL) * capacidad - (((aquarios * (aquarios + 1LL)) / 2LL) * diferencia);
		cout<<res<<"\n";
	}
	return 0;
}
