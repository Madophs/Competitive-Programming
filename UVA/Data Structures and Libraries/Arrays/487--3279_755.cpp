#include <bits/stdc++.h>

using namespace std;

char mapping(char c){
	if(isdigit(c)) return c;
	if(c == 'A' || c == 'B' || c == 'C') return '2';
	if(c == 'D' || c == 'E' || c == 'F') return '3';
	if(c == 'G' || c == 'H' || c == 'I') return '4';
	if(c == 'J' || c == 'K' || c == 'L') return '5';
	if(c == 'M' || c == 'N' || c == 'O') return '6';
	if(c == 'P' || c == 'R' || c == 'S') return '7';
	if(c == 'T' || c == 'U' || c == 'V') return '8';
	return '9';
}

string converToTelephone(string str){
	string telephone = "";
	for(int i=0; i<str.length(); i++){
		if(str[i] == '-') continue;
		if(telephone.length()==3) telephone+='-';
		telephone+=mapping(str[i]);
	}
	return telephone;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int datasets, numTelephones;
	string line;
	bool jump = false;
	cin>>datasets;
	while(datasets--){
		if(jump) cout<<'\n';
		jump = true;
		cin>>numTelephones;
		unordered_map<string,int> data;
		vector<string> telephones;
		while(numTelephones-- && cin>>line){
			string tel = converToTelephone(line);
			if(data.find(tel) == data.end()){
				data[tel] = 1;
			}else{
				++data.find(tel)->second;
				if(data.find(tel)->second == 2)
					telephones.push_back(tel);
			}
		}
		if(!telephones.empty()){
			sort(telephones.begin(), telephones.end());
			for(auto it = telephones.begin(); it!=telephones.end(); it++)
				cout<<*it<<" "<<data.find(*it)->second<<'\n';
		}else{
			cout<<"No duplicates.\n";
		}
	}
	return 0;
}