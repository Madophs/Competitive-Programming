#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string message;
	unordered_map<int, int> count;
	cin>>n;
	cin.ignore();
	while(n--){
		getline(cin,message);
		stringstream ss(message);
		string from,token;
		ss>>from;
		int inc = from=="G:"?2:1;
		while(ss>>token){
			if(regex_match(token,regex("^[0-9]+$"))){
				int tempDate = atoi(token.c_str());
				auto aux = count.find(tempDate);
				if(aux==count.end()){
					count[tempDate] = inc;
				}else{
					aux->second+=inc;
				}
			}
		}
		
	}
	int maxValue = -1, date=0,duplicates=0;
	for(auto iter = count.begin(); iter!=count.end(); iter++){
		if(maxValue<iter->second){
			duplicates = 0;
			date = iter->first;
			maxValue = iter->second;
		}else if(maxValue==iter->second){
			++duplicates;
		}
	}
	if(duplicates!=0 || (date!=19 && date!=20)){
		cout<<"No Date\n";
	}else{
		cout<<"Date\n";
	}
	return 0;
}