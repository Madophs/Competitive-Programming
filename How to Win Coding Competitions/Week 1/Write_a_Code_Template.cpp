#include "edx-io.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Location{
	int x,y;
};

int main(){
	int width, height;
	string line;
	vector<Location> keys(127);
	io>>width>>height;
	for(int x=0; x<height; x++){
		io>>line;
		for(int y=0; y<line.length(); y++){
			keys[line[y]].x = x;
			keys[line[y]].y = y;
		}
	}
	string language,tempLanguage, str;
	int minimum = 1e9, tempminimum;
	while(true){
		str = "";
		tempminimum = 0;
		io>>tempLanguage;
		if(tempLanguage.empty())break;
		io>>line;
		while(true){
			io>>line;
			if(line == "%TEMPLATE-END%")break;
			str+=line;
		}
		for(int x=0; x<str.length()-1; x++){
			int diff = max(abs(keys[str[x]].x - keys[str[x+1]].x),abs(keys[str[x]].y - keys[str[x+1]].y));
			tempminimum+=diff;
		}
		if(minimum > tempminimum){
			language = tempLanguage;
			minimum = tempminimum;
		}
	}
	io<<language<<"\n";
	io<<minimum<<"\n";
	return 0;
}