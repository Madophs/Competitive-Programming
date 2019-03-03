#include <bits/stdc++.h>

using namespace std;

int main() {
	int singers;
	cin>>singers;
	string name;
	vector<string> names,text={"Happy","birthday","to","you"};
	while(singers--){
		cin>>name;
		names.push_back(name);
	}
	int cont=0;
	bool finished=false;
	while(true){
		for(int x=0; x<4; x++){
			for(int y=0; y<4; y++){
				if(x==2 && y==3){
					cout<<names[cont]<<": Rujia\n";
				}else{
					cout<<names[cont]<<": "<<text[y]<<"\n";
				}

				++cont;
				if(cont>=names.size()){
					cont=0;
					finished=true;
				}
			}
		}

		if(finished)break;
	}
    return 0;
}