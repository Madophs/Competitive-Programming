#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	string message;
	while(cin>>size>>message){
		unordered_map<string,int> frec;
		int maximum = 0;
		string ans = "";
		for(int i = 0; i<message.length()-size; i++){
			string temp = message.substr(i,size);
			if(frec.find(temp) == frec.end()){
				frec[temp] = 1;
			}else{
				++frec.find(temp)->second;
			}
			if(frec.find(temp)->second > maximum){
				ans = temp;
				maximum = frec.find(temp)->second;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}