#include <bits/stdc++.h>

using namespace std;

int getMax(int l, int r){
	int auxMsb = l^r, msb=0;
	while(auxMsb){
		++msb;
		auxMsb>>=1;
	}
	int maxValue = 0, bitSum=1;
	while(msb--){
		maxValue+=bitSum;
		bitSum<<=1;
	}
	return maxValue;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l,r;
	cin>>l>>r;
	cout<<getMax(l,r)<<endl;
	return 0;
}