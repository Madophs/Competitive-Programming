#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int size, day, month,ways=0,i=0;
	cin>>size;
	++size;
	int chocolate[size];
	chocolate[0] = 0;
	for(int x=1; x<size; x++){
		cin>>chocolate[x];
		chocolate[x]+=chocolate[x-1];
	}
	cin>>day>>month;
	while(month<size){
		if(chocolate[month]-chocolate[i]==day)++ways;
		++i,++month;
	}
	cout<<ways<<endl;
	return 0;
}