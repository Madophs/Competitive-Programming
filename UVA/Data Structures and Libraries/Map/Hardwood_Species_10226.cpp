#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(4);
	map<string,double> trees;
	int tests;
	string line;
	cin>>tests;
	cin.ignore();
	cin.ignore();
	for(int t = 0; t<tests; t++){
		if(t) cout<<"\n";
		trees.clear();
		double total = 0.0;
		while(getline(cin,line) && !line.empty()){
			total++;
			if(trees.find(line) == trees.end()){
				trees[line] = 1.0;
			}else{
				trees.find(line)->second++;
			}
		}
		double porcentage;
		for(auto it = trees.begin(); it!=trees.end(); it++){
			porcentage = (it->second*100.0)/total;
			cout<<it->first<<" "<<porcentage<<"\n";
		}
	}
	return 0;
}