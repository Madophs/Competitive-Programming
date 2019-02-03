#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

bool ordenamiento(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}
bool sortChambers(pair<int,pair<int,int> > a, pair<int, pair<int,int> > b){
	return a.first<b.first;
}
int main() {
	ios::sync_with_stdio(false);
	int c,s,set=0;
	while(cin>>c>>s){
		double am=0;
		int var=0;
		vector< pair<int,int> > mass;
		for(int x=0; x<s; x++){
			cin>>var;
			mass.push_back(make_pair(var,x));
			am+=(double)(var);
		}
		am/=c;
		if(s<2*c){
			int cont=abs((2*c)-s);
			while(cont--)mass.push_back(make_pair(0,inf));
		}
		sort(mass.begin(), mass.end(), ordenamiento);
		vector< pair<int,pair<int,int> > > result;
		for(int x=0,y=mass.size()-1; x<=y; x++,y--){
			if(x==y){
				result.push_back(make_pair(mass[x].second,make_pair(mass[x].first,inf)));
				continue;
			}
			if(mass[x].second<mass[y].second){
				result.push_back(make_pair(mass[x].second,make_pair(mass[x].first,mass[y].first)));
			}else{
				result.push_back(make_pair(mass[y].second,make_pair(mass[y].first, mass[x].first)));
			}
		}
		sort(result.begin(), result.end(),sortChambers);
		cout<<"Set #"<<++set<<"\n";
		int caso=0;
		double imbalance=0.0;
		for(auto iter = result.begin(); iter!=result.end(); iter++){
			auto ref=*iter;
			if(ref.second.first==0){
				cout<<" "<<caso<<":\n";
				++caso;
				imbalance+=abs(0.0-am);
				continue;
			}
			if(ref.second.second==inf || ref.second.second==0){
				double m=(double)ref.second.first;
				cout<<" "<<caso<<": "<<ref.second.first<<"\n";
				imbalance+=abs(m-am);
			}else{
				double m = (double)(ref.second.first+ref.second.second);
				cout<<" "<<caso<<": "<<ref.second.first<<" "<<ref.second.second<<"\n";
				imbalance+=abs(m-am);
			}
			++caso;
		}
		cout<<fixed<<setprecision(5)<<"IMBALANCE = "<<imbalance<<"\n\n";
	}
	return 0;
}
