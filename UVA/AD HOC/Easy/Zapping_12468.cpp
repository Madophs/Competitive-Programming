#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int current,go;
	while(cin>>current>>go){
		if(current==-1 && go==-1)break;
		if(current>go){
			int temp=current;
			current=go;
			go=temp;
		}
		int dist1=abs(current-go),dist2=(100-go)+current,ans=min(dist1,dist2);
		cout<<ans<<"\n";
	}
}
