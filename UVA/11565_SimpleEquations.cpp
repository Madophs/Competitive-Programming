#include <iostream>
using namespace std;

int main(){
	int c=0;
	cin>>c;
	while(c--){
		int a,b,c;
		cin>>a>>b>>c;
		bool encontrado =false;
		for(int x=-100; x<=100 && !encontrado; x++){
			for(int y=-100; y<=100 && !encontrado; y++){
				for(int z=-100; z<=100 && !encontrado; z++){
					if((x*x +y*y+z*z)==c && (x*y*z)==b && ( x+y+z)==a && (x!=y) && y!=z && x!=z){
						cout<<x<<" "<<y<<" "<<z<<endl;
						encontrado=true;
					}
				}
			}
		}
		if(!encontrado)cout<<"No solution."<<endl;
	}
	return 0;
}
