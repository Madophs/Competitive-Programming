#include <bits/stdc++.h>

using namespace std;

int minPossibleLength(string &str){
	int answer = 0;
	int ocurrences[27];
	memset(ocurrences, 0, sizeof ocurrences);
	for(char c : str){
		answer = max(answer, ++ocurrences[c-'a']);
	}
	return (int)str.length()-answer;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int length;
	cin>>length;
	cin>>str;
	cout<<minPossibleLength(str)<<"\n";
	return 0;
}
