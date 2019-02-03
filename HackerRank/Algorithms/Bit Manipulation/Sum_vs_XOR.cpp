#include <bits/stdc++.h>

using namespace std;

unsigned long long getSum(unsigned long long &num){
	int msb=0;
	unsigned long long sum = 0,aux=num;
	while(aux){
		++msb;
		aux>>=1;
	}
	for(int x=0,y=0; x<msb; x++){
		if(!(num & 1LL<<x)){
			sum|=1LL<<y;
			++y;
		}
	}
	return sum+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long n;
	cin>>n;	
	cout<<getSum(n)<<endl;
	return 0;
}