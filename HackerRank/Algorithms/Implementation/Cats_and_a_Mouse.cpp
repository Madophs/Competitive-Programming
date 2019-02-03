#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int catA,catB,mouse,n;
	cin>>n;
	while(n--){
		cin>>catA>>catB>>mouse;
		int difA = abs(mouse-catA), difB = abs(mouse-catB);
		if(difA == difB){
			cout<<"Mouse C\n";
		}else if(difA<difB){
			cout<<"Cat A\n";
		}else{
			cout<<"Cat B\n";
		}
	}
	return 0;
}