#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> reverseLetter;
void initReverseLetters(){
	reverseLetter['A'] = 'A';
	reverseLetter['E'] = '3';
	reverseLetter['H'] = 'H';
	reverseLetter['I'] = 'I';
	reverseLetter['J'] = 'L';
	reverseLetter['L'] = 'J';
	reverseLetter['M'] = 'M';
	reverseLetter['O'] = 'O';
	reverseLetter['S'] = '2';
	reverseLetter['T'] = 'T';
	reverseLetter['U'] = 'U';
	reverseLetter['V'] = 'V';
	reverseLetter['W'] = 'W';
	reverseLetter['X'] = 'X';
	reverseLetter['Y'] = 'Y';
	reverseLetter['Z'] = '5';
	reverseLetter['1'] = '1';
	reverseLetter['2'] = 'S';
	reverseLetter['3'] = 'E';
	reverseLetter['5'] = 'Z';
	reverseLetter['8'] = '8';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	initReverseLetters();
	string palindrome;
	while(cin>>palindrome){
		bool mirrorPalindrome = true, regularPalindrome = true;
		for(int i = 0, j = palindrome.length()-1; i<=j; i++,j--){
			if(palindrome[i]!=palindrome[j]) regularPalindrome = false;
			if(reverseLetter.find(palindrome[i]) != reverseLetter.end() && reverseLetter.find(palindrome[j]) != reverseLetter.end()){
				if(reverseLetter.find(palindrome[i])->second != palindrome[j])
					mirrorPalindrome = false;
			}else{
				mirrorPalindrome = false;
			}
		}
		if(mirrorPalindrome && regularPalindrome){
			cout<<palindrome<<" -- is a mirrored palindrome.\n";
		}else if(regularPalindrome){
			cout<<palindrome<<" -- is a regular palindrome.\n";
		}else if(mirrorPalindrome){
			cout<<palindrome<<" -- is a mirrored string.\n";
		}else{
			cout<<palindrome<<" -- is not a palindrome.\n";
		}
		cout<<"\n";
	}
	return 0;
}