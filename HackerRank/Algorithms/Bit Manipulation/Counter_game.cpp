#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,num;
	bool turn;
	cin>>t;
	while(t--){
		cin>>num;
		turn = false;
		while(num!=1){
			turn=!turn;
			if(num && !(num & (num-1))){
				num>>=1;
			}else{
				long long power = 1;
				while(power<<1< num)power<<=1;
				num -= power;
			}
		}
		cout<<(turn?"Louise\n":"Richard\n");
	}	
	return 0;
}