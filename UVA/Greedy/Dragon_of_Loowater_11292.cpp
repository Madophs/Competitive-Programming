#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int heads,knights;
	while(cin>>heads>>knights && (heads || knights)){
		int hSize[heads],hKnights[knights];
		for(int x=0; x<heads; x++)cin>>hSize[x];
		for(int x=0; x<knights; x++)cin>>hKnights[x];
		if(heads>knights){
			cout<<"Loowater is doomed!\n";
		}else{
			int coins=0;
			sort(hSize,hSize+heads);
			sort(hKnights,hKnights+knights);
			int x=0,y=0;
			while(x<knights && y<heads){
				if(hKnights[x]>=hSize[y]){
					coins+=hKnights[x];
					++x,++y;
				}else{
					++x;
				}
			}
			if(y==heads){
				cout<<coins<<"\n";
			}else{
				cout<<"Loowater is doomed!\n";
			}
		}
	}
	return 0;
}
