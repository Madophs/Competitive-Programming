#include <bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int size,q,num;
	int numbers[1002];
	memset(numbers,0,sizeof(numbers));
	cin>>size;
	while(size--){
		cin>>num;
		++numbers[num];
	}
	cin>>q;
	while(q--){
		cin>>num;
		if(numbers[num]){
			cout<<numbers[num]<<"\n";
		}else{
			cout<<"NOT PRESENT\n";
		}
	}
	return 0;
}