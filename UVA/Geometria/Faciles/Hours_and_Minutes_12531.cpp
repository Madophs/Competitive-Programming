#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int angle;
	while(cin>>angle){
		if(angle%6==0){
			cout<<"Y\n";
		}else{
			cout<<"N\n";
		}
	}
	return 0;
}
