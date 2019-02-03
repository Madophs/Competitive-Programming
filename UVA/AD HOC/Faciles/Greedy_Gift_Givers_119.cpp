#include <bits/stdc++.h>

using namespace std;

struct Gift{
	int spent=0;
	int recieve=0;
	int order=0;
	string name;
	Gift(int order=1,string name="hola"):order(order),name(name){}
};

bool mdsSort(Gift a, Gift b){
	return a.order>b.order;
}
int main(){
	ios::sync_with_stdio(false);
	int people;
	string name;
	bool salto=false;
	while(cin>>people){
		if(salto)cout<<"\n";
		salto=true;
		unordered_map<string,Gift> mapa;
		for(int x=people; x--; ){
			cin>>name;
			Gift g(x,name);
			mapa[name]=g;
		}
		string from,to;
		int money,friends,spent=0;
		for(int x=people; x--; ){
			cin>>from>>money>>friends;
			mapa.find(from)->second.spent=money-(money%(friends>0?friends:numeric_limits<int>::max()));
			spent=friends>0?money/friends:0;
			while(friends--){
				cin>>to;
				mapa.find(to)->second.recieve+=spent;
			}
		}
		vector< Gift > ans;
		for(auto iter = mapa.begin(); iter!=mapa.end(); iter++){
			auto ref=*iter;
			ans.push_back(ref.second);
		}
		sort(ans.begin(),ans.end(), mdsSort);
		for(auto iter = ans.begin(); iter!=ans.end(); iter++){
			auto ref=*iter;
			cout<<ref.name<<" "<<(ref.recieve-ref.spent)<<"\n";
		}
	}
    return 0;
}