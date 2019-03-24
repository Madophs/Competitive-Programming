#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, depth, ball;
	cin>>test;
	while(test-- && cin>>depth>>ball){
		long long tree = 1;
		for(int i = 0; i<depth-1; i++){
			if(ball&1){
				tree<<=1;
			}else{
				(tree<<=1)++;
			}
			ball = ceil((double)ball/2.0);
		}
		cout<<tree<<"\n";
	}
	cin>>test;
	return 0;
}