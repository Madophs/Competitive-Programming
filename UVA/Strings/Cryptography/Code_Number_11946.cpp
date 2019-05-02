#include <bits/stdc++.h>

using namespace std;

char arr[] = {'O','I','Z','E','A','S','G','T','B','P'};

char digitsToNumbers(char c){
	if(!isdigit(c)) return c;
	return arr[c-'0'];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	string line;
	cin>>test;
	cin.ignore();
	for(int t = 0; test--; t++){
		if(t) cout<<"\n";
		while(getline(cin,line) && !line.empty()){
			transform(line.begin(), line.end(), line.begin(), digitsToNumbers);
			cout<<line<<"\n";
		}
	}
	return 0;
}
