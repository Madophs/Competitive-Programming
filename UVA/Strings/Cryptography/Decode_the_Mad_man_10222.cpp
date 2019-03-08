#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	vector<string> keyboard;
	keyboard.push_back("]\\qwertyuiop[]\\");
	keyboard.push_back(";'asdfghjkl;'");
	keyboard.push_back("./zxcvbnm,./");
	while(getline(cin,line)){
		string ansLine = "";
		for(int i = 0; i<line.length(); i++){
			char letter = tolower(line.at(i));
			if(letter == ' '){
				ansLine+=" ";
				continue;
			}
			bool found = false;
			for(int x = 0; x<3 && !found; x++){
				for(int y=2; y<keyboard[x].length() && !found; y++){
					if(letter == keyboard[x][y]){
						ansLine+=keyboard[x][y-2];
						found = true;
					}
				}
			}
		}
		cout<<ansLine<<"\n";
	}	
	return 0;
}