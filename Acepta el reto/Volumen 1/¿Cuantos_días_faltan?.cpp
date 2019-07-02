#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dias[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};	
	int casos, dia, mes;
	cin>>casos; 
	while(casos-- && cin>>dia>>mes){
		cout<<(365-(dias[mes]+dia))<<"\n";
	}
	return 0;
}
