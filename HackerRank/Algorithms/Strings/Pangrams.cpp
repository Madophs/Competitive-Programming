#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin,s);
	bitset<26> letters;
	for(auto iter = s.begin(); iter!=s.end(); iter++){
		if(*iter == ' ')continue;
		letters.set(tolower(*iter)-'a');
	}
	cout<<(letters.count()==26?"pangram\n":"not pangram\n");
	return 0;
}
