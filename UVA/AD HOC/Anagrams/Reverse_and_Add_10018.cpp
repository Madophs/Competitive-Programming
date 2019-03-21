#include <bits/stdc++.h>

using namespace std;

long long int reverseInt(long long int num){
	string ret = "", aux = to_string(num);
	for(int i = aux.length()-1; i>=0; i--) ret+=aux[i];
	return atoll(ret.c_str());
}

bool isPalindrome(long long int num){
	string str = to_string(num);
	for(int i = 0, j = str.length()-1; i<=j; i++,j--) if(str[i]!=str[j]) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int num = 4294967295;
	int tests, i;
	cin>>tests;
	while(tests-- && cin>>num){
		for(i = 1; i<=1001; i++){
			num+=reverseInt(num);
			if(isPalindrome(num)) break;
		}
		cout<<i<<" "<<num<<"\n";
	}
	return 0;
}