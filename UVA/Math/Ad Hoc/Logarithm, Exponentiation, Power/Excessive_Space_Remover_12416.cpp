#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	while(getline(cin,line)){
		int maxConsecutive = 0, consecutive = 0;
		for(int i = 0; i<line.length(); i++){
			if(line[i] == ' '){
				++consecutive;
			}else{
				consecutive = 0;
			}
			maxConsecutive = max(maxConsecutive, consecutive);
		}
		cout<<ceil(log2(maxConsecutive))<<"\n";
	}
	return 0;
}
