#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int c=0;
	while(cin>>c && c){
		cout<<std::setfill('1')<<setw(c)<<""<<endl;
	}
	return 0;
}
