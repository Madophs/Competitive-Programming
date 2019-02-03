#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,k;
	string word;
	cin>>n>>word>>k;
	for(int x=0; x<word.length(); x++){
		if(!isalpha(word.at(x)))continue;
		if(isupper(word.at(x))){
			if(word[x]+k<='Z'){
				word[x]+=k;
			}else{
				int aux = ((word[x]+k-'A')%26)+'A';
				word[x] = (char)aux;
			}
		}else{
			if(word[x]+k<='z'){
				word[x]+=k;
			}else{
				int aux = ((word[x]+k-'a')%26)+'a';
				word[x] = (char)aux;
			}
		}
	}
	cout<<word<<endl;
	return 0;
}