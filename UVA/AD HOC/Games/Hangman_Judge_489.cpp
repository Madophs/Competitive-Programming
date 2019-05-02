#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int round;
	int secretLetters, answersLetters, uniqueLetters;
	string secret, answers;
	while(cin>>round && round != -1){
		cin>>secret>>answers;
		secretLetters = answersLetters = uniqueLetters = 0;
		for(int i = 0; i<secret.length(); i++){
			secretLetters |= 1<<(secret[i]-'a');
		}
		int limit = 7;
		for(int i = 0; i<answers.length() && limit; i++){
			if(secretLetters & 1<<(answers[i]-'a')){
				answersLetters |= 1<<(answers[i]-'a');
			}else if(!(uniqueLetters & 1<<(answers[i]-'a'))){
				uniqueLetters |= 1<<(answers[i]-'a');
				--limit;
			}
		}
		cout<<"Round "<<round<<"\n";
		if(limit <= 0 && secretLetters != answersLetters){
			cout<<"You lose.\n";
		}else if(secretLetters != answersLetters){
			cout<<"You chickened out.\n";
		}else{
			cout<<"You win.\n";
		}
	}
	return 0;
}