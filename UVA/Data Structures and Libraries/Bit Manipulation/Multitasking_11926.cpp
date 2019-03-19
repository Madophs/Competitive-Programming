#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bitset<1000001> calendar;
	int n,m, start, finish, range;
	while(cin>>n>>m && (n || m)){
		calendar.set();
		bool conflict = false;
		while(n-- && cin>>start>>finish){
			for(int i = start; i<finish && !conflict; i++){
				if(!calendar.test(i)){
					conflict = true;
				}else{
					calendar.reset(i);
				}
			}
		}
		while(m-- && cin>>start>>finish>>range){
			while(!conflict){
				int i;
				for(i = start; i<finish && i < 1e6 && !conflict; i++){
					if(!calendar.test(i)){
						conflict = true;
					}else{
						calendar.reset(i);
					}
				}
				if(i >= 1e6)break;
				start+=range, finish+=range;
			}
		}
		if(conflict){
			cout<<"CONFLICT\n";
		}else{
			cout<<"NO CONFLICT\n";
		}
	}
	return 0;
}
