#include <bits/stdc++.h>

using namespace std;

int countDigits(int num){
	if(!num) return num;
	return floor(log10(num))+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2;
	while(cin>>n1>>n2 && (n1 || n2)){
		string num1(15-countDigits(n1),'0');
		string num2(15-countDigits(n2),'0');
		num1+=to_string(n1), num2+=to_string(n2);
		int carry = 0, carries = 0;
		for(int i = num2.length()-1; i>=0; i--){
			int aux = (num1[i]-'0')+(num2[i]-'0')+carry;
			if(aux>9){
				carry = aux/10;
				++carries;
			}else{
				carry = 0;
			}
		}
		if(carries == 1){
			cout<<"1 carry operation.\n";
		}else if(carries > 1){
			cout<<carries<<" carry operations.\n";
		}else{
			cout<<"No carry operation.\n";
		}
	}
	return 0;
}