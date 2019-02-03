#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	string sequence;
	while(t--){
		cin>>sequence;
		map<char,vector<int>,less<char> > adresses;
		for(int x=0; x<sequence.length(); x++){
			if(adresses.find(sequence.at(x))==adresses.end()){
				vector<int> vec(1,x);
				adresses[sequence.at(x)]=vec;
			}else{
				adresses.find(sequence.at(x))->second.push_back(x);
			}
		}
		auto iter = adresses.begin()->second;
		string cad1=sequence.substr(iter[0],string::npos)+((iter[0]>0)?sequence.substr(0,iter[0]):""),cad2="";
		for(int x=1; x<iter.size(); x++){
			cad2=sequence.substr(iter[x],string::npos)+sequence.substr(0,iter[x]).c_str();
			bool res = std::lexicographical_compare(cad1.begin(),cad1.end(),cad2.begin(), cad2.end());
			if(!res){
				cad1=cad2;
			}
		}
		cout<<cad1<<"\n";
	}
    return 0;
}
