#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, original, translated;
	unordered_map<string,string> dic;
	while(getline(cin,line) && !line.empty()){
		stringstream ss(line);
		ss>>translated>>original;
		dic[original] = translated;
	}
	while(cin>>original){
		if(dic.find(original) != dic.end()){
			cout<<dic.find(original)->second<<"\n";
		}else{
			cout<<"eh\n";
		}
	}
	return 0;
}