#include <iostream>
#include <vector>
using namespace std;

int main(){
	int c=0,alt=0;
	while(cin>>c && c){
		vector<int> vec(c+1,0);
		for(int x=1; x<=c; x++){
			cin>>vec[x];
		}
		vec[0]=vec.back();
		vec.push_back(vec[1]);
		int picos=0,i=0,j=2;
		for(int x=1; x<vec.size()-1; x++){
			if(vec[i]<vec[x] && vec[j]<vec[x]){
				++picos;
			}
			++i;
			++j;
		}
		cout<<picos<<endl;
	}
	return 0;
}
