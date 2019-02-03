#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int main(){
	//std::ios_base::sync_with_stdio(true);
	string cadena="";
	while(getline(cin,cadena) && !cadena.empty()){
		stringstream tk(cadena);
		int val=0;
		tk>>val;
		int horse[val][val];
		for(int x=0; x<val; x++){
			for(int y=0; y<val;y++){
				scanf("%d",&horse[x][y]);
				if(x>0)horse[x][y]+=horse[x-1][y];
				if(y>0)horse[x][y]+=horse[x][y-1];
				if(x>0 && y>0)horse[x][y]-=horse[x-1][y-1];
			}
		}
		int res=-1e9;
		for(int x=0; x<val; x++){
			for(int y=0; y<val; y++){
				for(int i=x; i<val; i++){
					for(int j=y; j<val; j++){
						int subrecta=horse[i][j];
						if(x>0)subrecta-=horse[x-1][j];
						if(y>0)subrecta-=horse[i][y-1];
						if(x>0 && y>0)subrecta+=horse[x-1][y-1];
						res=max(subrecta,res);
					}
				}
			}
		}
		printf("%d\n",res);
		cin.ignore();
	}
	return 0;
}
