#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int counting[10];
	int digit, tests;
	cin>>tests;
	while(tests-- && cin>>digit){
		memset(counting, 0, sizeof counting);
		string stringValue;
		for(int i = 1; i<=digit; i++){
			stringValue = to_string(i);
			for(int j = 0; j<stringValue.length(); j++)
				++counting[stringValue[j]-'0'];
		}
		for(int i = 0; i<10; i++){
			if(i) cout<<" ";
			cout<<counting[i];
		}
		cout<<"\n";
	}
	return 0;
}
