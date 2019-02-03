#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,c=0;
	cin>>t;
	while(t--){
		vector<string> sites;
		string site;
		int high=-1,relevance=0;
		for(int x=0; x<10; x++){
			cin>>site>>relevance;
			if(relevance==high){
				sites.push_back(site);
			}else if(relevance>high){
				high=relevance;
				sites.clear();
				sites.push_back(site);
			}
		}
		cout<<"Case #"<<++c<<":\n";
		for(auto iter = sites.begin(); iter!=sites.end(); iter++){
			cout<<*iter<<"\n";
		}
	}
    return 0;
}