#include <bits/stdc++.h>

using namespace std;

string generatePalindrome(string palindrome,int i, int j,string number){
	while(palindrome<=number && palindrome[i]<'9'){
		if(i+1<=j-1) palindrome = generatePalindrome(palindrome,i+1,j-1,number);
		if(palindrome>number) return palindrome;
		palindrome[i] = palindrome[j] = palindrome[i]+1;
	}
	if(palindrome<=number && i>0){
		palindrome[i] = palindrome[j] = '0';
	}
	return palindrome;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,x;
	string number;
	cin>>t;
	while(t--){
		cin>>number;
		if(number == string(number.length(),'9')){
			string ans(number.length()+1,'0');
			++ans[0],++ans[ans.length()-1];
			cout<<ans<<'\n';
		}else if(number.length()>2){
			string ans(number.length(),'9');
			ans[0] = ans[ans.length()-1] = number[0];
			if(ans<=number){
				ans.assign(number.length()+1,'0');
				ans[0] = ans[ans.length()-1] = number[0]+1;
				cout<<ans<<'\n';
			}else{
				if(number.length() & 1){
					string cad(number.length(),'0');
					for(int x=0; x<number.length()/2+1; x++){
						cad[x] = cad[number.length()-1-x] = number[x];
					}
					string ans = generatePalindrome(cad,0,number.length()-1,number);
					cout<<ans<<'\n';
				}else{
					string cad(number.length(),'0');
					for(int x=0; x<number.length()/2; x++){
						cad[x] = cad[number.length()-1-x] = number[x];
					}
					string ans = generatePalindrome(cad,0,number.length()-1,number);
					cout<<ans<<'\n';
				}
			}
		}else{
			cout<<++number[0]<<'\n';
		}
	}
	return 0;
}