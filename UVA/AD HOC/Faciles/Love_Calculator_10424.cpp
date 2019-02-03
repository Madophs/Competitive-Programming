#include <bits/stdc++.h>

using namespace std;

int getSum(string &name){
	int sum=0,ret=0;
	for(auto iter = name.begin(); iter!=name.end(); iter++){
		if(isalpha(*iter)){
			if(isupper(*iter)){
				sum+=(int)(*iter-64);
			}else{
				sum+=(int)(*iter-96);
			}
		}
	}
	while(true){
		while(sum){
			ret+=sum%10;
			sum/=10;
		}
		if(ret<10)break;
		sum=ret;
		ret=0;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	string nom1,nom2;
	int sum1,sum2;
	while(getline(cin,nom1) && !nom1.empty()){
		getline(cin,nom2);
		sum1=getSum(nom1),sum2=getSum(nom2);
		float divisor=max(sum1,sum2),dividendo=min(sum1,sum2),ans=dividendo/divisor;
		ans*=100;
		cout<<fixed<<setprecision(2)<<ans<<" %\n";
	}
}
