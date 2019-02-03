#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int count;
	unsigned long long number,res=0;
	cin>>count;
	for(int x=0; x<count; x++){
		cin>>number;
		res+=number;
	}
	cout<<res<<endl;
	return 0;
}