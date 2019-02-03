 #include <bits/stdc++.h>

using namespace std;

int main() {
	int pot,bet,remainer;
	while(cin>>pot>>bet>>remainer && (pot || bet || remainer)){
		int dif=abs(pot-remainer);
		double div=((double)(dif)/(double)(bet)), noDecimal=floor(div);
		if(noDecimal!=div){
			cout<<"No accounting tablet\n";
			continue;
		}
		int division=static_cast<int>(div),players=0,aux=0;
		for(int x=3; x>=1 && division; x--){
			players+=(int)(floor((double)division/(double)x));
			aux=division%x;
			division=aux;
		}
		cout<<players<<"\n";
	}
	return 0;
}