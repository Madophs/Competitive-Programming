#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	string topics;
	cin>>n>>m;
	vector< bitset<500> > vec;
	while(n-- && cin>>topics)vec.push_back(bitset<500>(topics));
	int maxValue = 0, ways=1;
	bitset<500> aux;
	for(int x=0; x<vec.size()-1;x++){
		for(int y=x+1; y<vec.size(); y++){
			aux = vec[x] | vec[y];
			if(aux.count() >= maxValue){
				if(aux.count() == maxValue){
					++ways;
				}else{
					ways = 1;
					maxValue = aux.count();
				}
			}
		}
	}
	cout<<maxValue<<endl<<ways<<endl;
	return 0;
}