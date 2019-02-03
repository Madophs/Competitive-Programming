#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	ios_base::sync_with_stdio(false);
	map<string, vector<int> > ref;
	while(cin>>n && n){
		string cadena;
		cin.ignore();
		for(int x=1; x<=n; x++){
			getline(cin,cadena);
			transform(cadena.begin(),cadena.end(),cadena.begin(),::tolower);
			stringstream tk(cadena);
			string token="";
			while(tk>>token){
				if(token.size()<=2)continue;
				if(ref.find(token)==ref.end()){
					vector<int> tem;
					tem.push_back(x);
					ref.insert(make_pair(token,tem));
				}else{
					map<string, vector<int> >::iterator iter = ref.find(token);
					if(iter->second[iter->second.size()-1]!=x) iter->second.push_back(x);
				}
			}
		}
		for(map<string, vector<int> >::iterator iter = ref.begin(); iter!=ref.end(); iter++){
			cout<<iter->first;
			for(int x=0; x<iter->second.size();x++){
				cout<<" "<<iter->second[x];
			}
			cout<<"\n";
		}
		cout<<"----\n";
		ref.clear();
	}
	return 0;
}
