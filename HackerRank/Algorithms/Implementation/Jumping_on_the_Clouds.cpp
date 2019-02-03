#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,pos=0,jumps=0;
	cin>>n;
	int clouds[n];
	for(int x=0; x<n && cin>>clouds[x]; x++);
	do{
		if(clouds[(pos+2)%n]==0 && (pos+1)%n!=n-1){
			++jumps;
			pos = (pos+2)%n;
		}else{
			++jumps;
			pos = (pos+1)%n;
		}
	}while(pos!=n-1);
	cout<<jumps<<endl;
	return 0;
}