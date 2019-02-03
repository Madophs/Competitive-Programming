#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,number;
	string numberString;
	bool contains;
	cin>>q;
	while(q-- && cin>>number){
		numberString = to_string(number);
		contains = false;
		for(int x=0; x<numberString.length()-1; x++){
			if(numberString[x] == '2' && numberString[x+1] == '1'){
				contains = true;
				break;
			}
		}
		if(number%21==0 || contains){
			cout<<"The streak is broken!\n";
		}else{
			cout<<"The streak lives still in our heart!\n";
		}
	}	
	return 0;
}