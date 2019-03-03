#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string var;
		cin>>var;
		int num = atoi(var.c_str()), range = (var.length())*9,result=0;
		for(int x=(num>=10 && num-range>0)?num-range:0; x<=num; x++){
			int aux=x,res=0;
			while(aux>0){
				res+=aux%10;
				aux/=10;
			}
			if(x+res==num){
				result=x;
				break;
			}
		}
		cout<<result<<"\n";
	}
    return 0;
}