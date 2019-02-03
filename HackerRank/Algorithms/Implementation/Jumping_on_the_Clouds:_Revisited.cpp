#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,jump,energy=100,pos=0;
	cin>>n>>jump;
	int clouds[n];
	for(int x=0; x<n && cin>>clouds[x]; x++);
	do{
		pos = (pos+jump)%n;
		--energy;
		if(clouds[pos])energy-=2;
	}while(pos);
	cout<<energy<<endl;
	return 0;
}