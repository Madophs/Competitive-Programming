#include <bits/stdc++.h>

using namespace std;

vector<bool> getLetters(string &str){
	vector<bool> vec(26, false);
	for(auto val : str)
		vec[val-'a'] = true;
	return vec;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	int cases;
	cin>>cases;
	while(cases-- && cin>>str1>>str2){
		vector<bool> letters = getLetters(str1);
		bool ans = false;
		for(char val : str2){
			if(letters[val-'a']){
				ans = true;
				break;
			}
		}
		cout<<(ans ? "YES\n" : "NO\n");
	}
	return 0;
}
