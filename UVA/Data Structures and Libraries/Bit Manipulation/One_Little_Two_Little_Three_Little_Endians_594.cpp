#include <bits/stdc++.h>

using namespace std;

int convertTo(unsigned int number){
	int reversed = 0, i;
	for(i = 0; i < 8; i++){
		if(number & 1 << i)
			reversed |= (1 << i);
	}
	reversed <<= 16, number >>= 8;
	for(i = 0; i < 16; i++){
		if(number & (1<<i)){
			if(i < 8)
				reversed |= (1 << (i+8));
			else
				reversed |= (1 <<(i-8));
		}
	}
	number >>= 16, reversed <<= 8;
	reversed += number;
	return (int)reversed;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number;
	while(cin>>number){
		cout<<number<<" converts to "<<convertTo(number)<<"\n";
	}
	return 0;
}
