#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string cad;
	while(cin>>cad){
		string ans="",aux="";
		bool home=false;
		for(auto iter = cad.begin(); iter!=cad.end(); iter++){
			if(*iter=='['){
				if(home){
					ans=aux+ans;
				}else{
					ans+=aux;
				}
				aux="";
				home=true;
			}else if(*iter==']'){
				if(home){
					ans=aux+ans;
				}else{
					ans+=aux;
				}
				aux="";
				home=false;
			}else{
				aux+=*iter;
			}
		}
		if(home){
			ans=aux+ans;
		}else{
			ans+=aux;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
