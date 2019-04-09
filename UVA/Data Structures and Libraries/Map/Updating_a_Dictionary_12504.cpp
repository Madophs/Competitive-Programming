#include <bits/stdc++.h>

using namespace std;

void removeCurlyBraces(string &s){
	s.erase(s.begin());
	s.erase(s.begin()+s.length()-1);
}

void fillDiccionaries(unordered_map<string,string> &dic, string line, unordered_set<string> &keys){
	stringstream ss(line);
	string token, key, value;
	while(getline(ss,token,',')){
		stringstream stoken(token);
		getline(stoken,key,':');
		getline(stoken,value,':');
		dic[key] = value;
		keys.insert(key);
	}
}

void printKeys(vector<string> &vec){
	sort(vec.begin(), vec.end());
	for(int i = 0; i<vec.size(); i++){
		if(i)cout<<",";
		cout<<vec[i];
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string newLine, oldLine;
	unordered_map<string,string> newDic, oldDic;
	unordered_set<string> allKeys;
	cin>>tests;
	while(tests--){
		cin>>oldLine>>newLine;
		newDic.clear(), oldDic.clear();
		allKeys.clear();
		removeCurlyBraces(oldLine);
		removeCurlyBraces(newLine);
		fillDiccionaries(oldDic,oldLine, allKeys);
		fillDiccionaries(newDic,newLine, allKeys);
		vector<string> plus, minus, star;
		for(auto i = allKeys.begin(); i!=allKeys.end(); i++){
			bool f1 = oldDic.find(*i) != oldDic.end(), f2 = newDic.find(*i) != newDic.end();
			if(f1 && f2){
				string v1 = oldDic.find(*i)->second, v2 = newDic.find(*i)->second;
				if(v1!=v2) star.emplace_back(*i);
			}else if(f1 && !f2){
				minus.emplace_back(*i);
			}else if(!f1 && f2){
				plus.emplace_back(*i);
			}
		}
		if(plus.empty() && minus.empty() && star.empty()){
			cout<<"No changes\n";
		}else{
			if(!plus.empty()){
				cout<<"+";
				printKeys(plus);
			}
			if(!minus.empty()){
				cout<<"-";
				printKeys(minus);
			}
			if(!star.empty()){
				cout<<"*";
				printKeys(star);
			}
		}
		cout<<"\n";
	}
	return 0;
}