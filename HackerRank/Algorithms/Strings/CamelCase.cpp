#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string words;
	cin>>words;
	int numWords = 0;
	for(string::iterator iter = words.begin(); iter!=words.end(); iter++){
		if(isupper(*iter))numWords++;
	}
	cout<<++numWords<<endl;
	return 0;
}