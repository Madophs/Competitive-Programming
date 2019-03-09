#include <bits/stdc++.h>

using namespace std;

struct Data{
	string carName;
	int lower, higher;
	Data(string name, int lower, int higher){
		this->carName = name;
		this->lower = lower;
		this->higher = higher;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, databases,queries,lower, higher,price;
	string car;
	cin>>tests;
	for(int t = 0;t<tests; t++){
		if(t) cout<<"\n";
		cin>>databases;
		vector<Data> data;
		while(databases-- && cin>>car>>lower>>higher) data.push_back(Data(car,lower,higher));
		cin>>queries;
		while(queries-- && cin>>price){
			int results = 0;
			string ans = "UNDETERMINED";
			for(int i = 0;i<data.size(); i++){
				if(price >= data[i].lower && price <= data[i].higher){
					++results;
					if(results == 1){
						ans = data[i].carName;
					}else{
						ans = "UNDETERMINED";
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}