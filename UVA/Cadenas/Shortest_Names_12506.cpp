#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,names;
	cin>>t;
	while(t--){
		cin>>names;
		string name;
		vector<string> vec;
		while(names--){
			cin>>name;
			vec.push_back(name);
		}
		sort(vec.begin(),vec.end());
		if(vec.size()==1){
			cout<<1<<"\n";
			continue;
		}
		int characters=0, aux=0,mov=0,limit=-1,limitAux=0;
		for(int x=0; x<vec.size()-1; x++){
			aux=0;
			mov=0;
			limitAux=0;
			while(true){
				if(vec[x].at(mov)==vec[x+1].at(mov)){
					++limitAux;
					if(mov>=limit){
						aux+=2;
					}else{
						++aux;
					}
					++mov;
				}else{
					++limitAux;
					if(mov>=limit){
						aux+=2;
					}else{
						++aux;
					}
					break;
				}
				if(mov>=vec[x].length() || mov>=vec[x+1].length()){
					++aux;
					if(mov>=vec[x+1].length()){
						++limitAux;
					}
					break;
				}
			}
			limit=limitAux;
			characters+=aux;
		}
		cout<<characters<<"\n";
	}
    return 0;
}
