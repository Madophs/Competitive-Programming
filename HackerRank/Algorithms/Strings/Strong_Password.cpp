#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int size;
	bool up, low, special,number;
	up=low=special=number=false;
	string password;
	cin>>size>>password;
	for(auto iter = password.begin(); iter!=password.end(); iter++){
		if(isalpha(*iter)){
			if(isupper(*iter))up = true;
			if(islower(*iter))low = true;
		}else if(isdigit(*iter)){
			number = true;
		}else{
			special = true;
		}
	}
	int sum = up+low+special+number,needed = 4-sum;
	if(needed==0 && size>=6){
		cout<<0<<endl;
	}else if(needed==0 && size<6){
		cout<<6-size<<endl;
	}else if(needed>0 && size>=6){
		cout<<needed<<endl;
	}else if(needed>0 && size<6){
		if(needed+size<6){
			cout<<6-size<<endl;
		}else{
			cout<<needed<<endl;
		}
	}
	return 0;
}