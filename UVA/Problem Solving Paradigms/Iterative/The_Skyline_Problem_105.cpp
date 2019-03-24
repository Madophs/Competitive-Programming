#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int l,h,r,first=0,last=-1;
	int highs[10002];
	string line;
	bool starting=true;
	memset(highs,0,sizeof(highs));
	while(getline(cin,line) && !line.empty()){
		stringstream ss(line);
		ss>>l>>h>>r;
		for(int x=l; x<r;x++){
			if(highs[x]<h)highs[x]=h;
		}
		if(starting)first=l;
		starting=false;
		last=max(r,last);
	}
	int aux=-1;
	for(int x=first; x<=last; x++){
		if(aux!=highs[x]){
			if(x!=first)cout<<" ";
			cout<<x<<" "<<highs[x];
			aux=highs[x];
		}
	}
	cout<<"\n";
	return 0;
}
