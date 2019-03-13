#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, value;
	string doubleValue;
	string line, line2;
	cin>>tests;
	cin.ignore();
	for(int t = 0;tests--; t++){
		if(t)cout<<"\n";
		cin.ignore();
		getline(cin,line);
		getline(cin,line2);
		stringstream ss(line);
		stringstream ss2(line2);
		vector<int> indexes;
		unordered_map<int,double> dic;
		while(ss>>value){
			indexes.push_back(value-1);
		}
		vector<string> vecValues(indexes.size(),"");
		for(int i = 0; ss2>>doubleValue; i++){
			vecValues[indexes[i]] = doubleValue;
		}
		for(int i = 0; i<indexes.size(); i++){
			cout<<vecValues[i]<<"\n";
		}
	}
	return 0;
}