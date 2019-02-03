#include <iostream>
#include <vector>
using namespace std;

int main(){
	int c=0, tem=0;
	cin>>c;
	while(c--){
		cin>>tem;
		vector<int> vec(tem,0);
		for(int x=0; x<tem; x++){
			cin>>vec[x];
		}
		int picos=0,valles=0,i=0,j=2;
		for(int x=1; x<vec.size()-1; x++){
			if(vec[i]<vec[x] && vec[j]<vec[x]){
				++picos;
			}
			if(vec[i]>vec[x] && vec[j]>vec[x]){
				++valles;
			}
			++i;
			++j;
		}
		cout<<picos<<" "<<valles<<endl;
	}
	return 0;
}
