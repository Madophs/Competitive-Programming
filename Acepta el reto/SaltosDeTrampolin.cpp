#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string cadena="";
	getline(cin,cadena);
	while(cadena.length()>0){
		char *p=std::strtok((char *)cadena.c_str()," ");
		vector<float> vec(7,-1);
		for(int x=0;p!=NULL;x++){
			vec[x]=static_cast<float>(std::atof(p));
			p=std::strtok(NULL," ");
		}
		std::sort(vec.begin(),vec.end());
		float res=0;
		for(int x=2; x<vec.size()-2;x++){
			res+=vec[x];
		}
		cout<<(res*2)<<endl;
		getline(cin,cadena);
	}
	return 0;
}
