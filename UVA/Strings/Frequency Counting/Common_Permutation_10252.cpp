#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line1, line2;
	int f1[27], f2[27];
	while(getline(cin,line1) && getline(cin,line2)){
		memset(f1,0, sizeof f1);
		memset(f2,0, sizeof f2);
		for(auto it = line1.begin(); it!=line1.end(); it++) ++f1[*it-'a'];
		for(auto it = line2.begin(); it!=line2.end(); it++) ++f2[*it-'a'];
		string permutation;
		for(int i = 0; i<27; i++){
			while(f1[i] && f2[i]){
				permutation+=(i+'a');
				--f1[i],--f2[i];
			}
		}
		cout<<permutation<<"\n";
	}
	return 0;
}