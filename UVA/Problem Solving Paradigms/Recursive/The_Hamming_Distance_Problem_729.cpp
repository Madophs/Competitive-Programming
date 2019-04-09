#include <bits/stdc++.h>

using namespace std;

string generateString(int d, int h){
	string ret = "";
	while(h--){
		ret += "1";
		--d;
	}
	while(d--) ret = "0"+ret;
	return ret;
}

string generateNextString(string &s, int &h){
	int pos = s.find_first_of('1')
}

bool isStillValid(string &s, int &h){
	int pos = s.find_first_of('1'), count = 0;
	for(; pos < s.length() && s[pos]=='1'; pos++,count++);
	return h!=count;
}

void printHammingStrings(string &s, int &hammingDistance){
	cout<<s<<"\n";
	cout<<isStillValid(s,hammingDistance)<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, length, hammingDistance;
	cin>>tests;
	for(int t = 0; t<tests; t++){
		cin>>length>>hammingDistance;
		if(t)cout<<"\n";
		string str = generateString(length,hammingDistance);
		printHammingStrings(str,hammingDistance);
	}
	return 0;
}