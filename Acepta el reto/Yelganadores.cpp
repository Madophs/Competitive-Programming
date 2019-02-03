#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n=0,globos=0,num=0;
	string color="";
	while(cin>>n>>globos && (globos || n)){
		vector<int> vec(n+1,0);
		vector<string> cadenas;
		while(globos--){
			cin>>num;
			cin.ignore();
			getline(cin,color);
			++vec[num];
		}
		int max=*std::max_element(vec.begin(),vec.end()),cont=0,pos=0;
		for(int x=1; x<vec.size(); x++){
			if(vec[x]==max){
				pos=x;
				++cont;
			}
		}
		if(cont>1){
			cout<<"EMPATE"<<endl;
		}else{
			cout<<pos<<endl;
		}
	}
	return 0;
}
