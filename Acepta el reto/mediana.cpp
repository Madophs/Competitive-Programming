#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int tam=0;
	while(cin>>tam && tam){
		vector<int> vec(tam,-1);
		for(int x=0; x<vec.size(); x++){
			cin>>vec[x];
		}
		std::sort(vec.begin(),vec.end());
		int a=vec[tam/2],b=vec[(tam/2)-1];
		cout<<(tam%2!=0?vec[tam/2]*2:((static_cast<double>(b+a))/2)*2)<<endl;
	}
	return 0;
}
