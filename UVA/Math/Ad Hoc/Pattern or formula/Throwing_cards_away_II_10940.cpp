#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int cards=500,n=1,cont=2;
	long ans[500001];
	ans[1]=1;
	bool continuar=true;
	while(continuar){
		for(int x=2; x<=(1<<n); x+=2){
			ans[cont]=x;
			if(cont==500000){
				continuar=false;
				break;
			}
			++cont;
		}
		++n;
	}
	while(cin>>cards && cards){
		cout<<ans[cards]<<"\n";
		--cards;
	}
	return 0;
}
