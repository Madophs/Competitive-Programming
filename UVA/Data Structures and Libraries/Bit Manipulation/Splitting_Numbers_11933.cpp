#include <bits/stdc++.h>
#define lsb(n) n&-n

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	while(cin>> num && num){
		int a=0, b=0;
		bool turn = true;
		while(num){
			if(turn){
				a|=lsb(num);
			}else{
				b|=lsb(num);
			}
			num ^= lsb(num);
			turn = !turn;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
