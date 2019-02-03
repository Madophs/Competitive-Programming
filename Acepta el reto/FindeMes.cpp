#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int c=0,in=0,fin=0;
	cin>>c;
	while(c--){
		cin>>in>>fin;
		if((in+fin)<0){
			cout<<"NO"<<endl;
		}else{
			cout<<"SI"<<endl;
		}
	}
	return 0;
}
