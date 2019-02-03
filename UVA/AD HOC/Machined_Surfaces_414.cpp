#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int image;
	string cad;
	while(cin>>image && image){
		vector<int> vec(image,0);
		cin.ignore();
		while(image--){
			getline(cin,cad);
			for(auto iter = cad.begin(); iter!=cad.end(); iter++){
				if(*iter=='X')++vec[image];
			}
		}
		if(vec.size()==1){
			cout<<0<<"\n";
		}else{
			sort(vec.begin(),vec.end());
			int highest=vec[vec.size()-1],ans=0;
			for(auto iter = vec.rbegin()+1; iter!=vec.rend(); iter++){
				ans+=abs(highest-*iter);
			}
			cout<<ans<<"\n";
		}

	}
	return 0;
}
