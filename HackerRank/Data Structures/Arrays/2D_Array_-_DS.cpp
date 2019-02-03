#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	const unsigned int size = 6;
	int hourglass[size][size];
	for(int x=0; x<size; x++)
		for(int y=0; y<size; y++)
			cin>>hourglass[x][y];

	int a=0, b=2,ans=-1e10,sum=0;
	for(int x=0; x<size-2;x++){
		a=0,b=3,sum=0;
		while(b<=size){
			for(int i=a; i<b; i++)sum+=hourglass[x][i]+hourglass[x+2][i];
			sum+=hourglass[x+1][a+1];
			ans = max(sum,ans);
			sum = 0;
			++a,++b;
		}
	}
	cout<<ans<<endl;
	return 0;
}