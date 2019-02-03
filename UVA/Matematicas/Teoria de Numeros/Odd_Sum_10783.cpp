#include <bits/stdc++.h>

using namespace std;

int numOddNumbers(int num){
	if(num==0)return num;
	return ((num-1)/2)+1;
}

int sumOddNumbers(int num){
	return pow(num,2);
}
int main(){
	ios::sync_with_stdio(false);
	int t,i,j,c=0;cin>>t;
	while(t--){
		cin>>i>>j;
		int sum1=sumOddNumbers(numOddNumbers(i-1)),sum2=sumOddNumbers(numOddNumbers(j));
		cout<<"Case "<<++c<<": "<<abs(sum1-sum2)<<endl;
	}
	return 0;
}
