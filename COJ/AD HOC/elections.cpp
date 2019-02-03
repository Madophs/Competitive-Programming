#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t=0;
	while(cin>>t && t){
		vector<int> v(t,-1);
		for(int x=0;x<t;x++){
			cin>>v[x];
		}
		int max = *std::max_element(v.begin(),v.end());
		int suma=0;
		for(int x=0; x<v.size(); x++){
			suma+=v[x];
		}
		if(max>=(suma*0.45)){
			cout<<1<<endl;
		}else{
			if(max>=(suma*0.40)){
				bool cierto =true;
				for(int x=0; x<v.size();x++){
					if((max<(v[x]+(suma*0.1))) && max!=v[x]){
						cierto=false;
						break;
					}
				}
				if(cierto){
					cout<<1<<endl;
				}else{
					cout<<2<<endl;
				}
			}else{
				cout<<2<<endl;
			}
		}
	}
	return 0;
}
