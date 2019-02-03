#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int size,q,l,r,op;
	cin>>size>>q;
	++size;
	bool bin[size];
	bin[0] = 0;
	for(int x=1; x<size; x++)cin>>bin[x];
	while(q--){
		cin>>op;
		if(op){
			cin>>l;
			bin[l] = !bin[l];
		}else{
			cin>>l>>r;
			cout<<(bin[r]?"ODD\n":"EVEN\n");
		}
	}
	return 0;
}