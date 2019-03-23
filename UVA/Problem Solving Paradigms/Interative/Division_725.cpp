#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, tests = 0;
	while(cin>>num && num){
		if(tests++)cout<<"\n";
		bool found = false;
		for(int i = 1234; i<=98765/num; i++){
			int j = i*num;
			int aux, mask = (i<10000);
			aux = i;
			while(aux){
				mask |= 1<<(aux%10);
				aux/=10;
			}
			aux = j;
			while(aux){
				mask |= 1<<(aux%10);
				aux/=10;
			}
			if(mask == (1<<10)-1){
				found = true;
				cout<<j<<" / "<<setw(5)<<setfill('0')<<i<<" = "<<num<<"\n";
			}
		}
		if(!found){
			cout<<"There are no solutions for "<<num<<".\n";
		}
	}
	return 0;
}