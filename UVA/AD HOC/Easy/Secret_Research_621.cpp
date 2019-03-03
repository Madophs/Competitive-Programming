#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string experiment="";
	string results[]={"1","4","78"};
	while(t--){
		cin>>experiment;
		if(experiment=="1" || experiment=="4" || experiment=="78"){
			cout<<"+\n";
			continue;
		}
		if(experiment.at(0)=='9' && experiment.at(experiment.length()-1)=='4'){
			cout<<"*\n";
			continue;
		}
		string res="?";
		if(experiment.substr(0,3)=="190"){
			res="?";
		}
		if(experiment.size()>=2){
			string temp = experiment.substr(experiment.size()-2,2);
			if(temp=="35")res="-";
		}
		cout<<res<<"\n";
	}
    return 0;
}