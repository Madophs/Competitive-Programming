#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	string line;
	bool blankLine = false;
	int i,j, sum;
	while(getline(cin,line)){
		if(blankLine) cout<<"\n";
		else blankLine = true;
		do{
			i = 0;
			while(i < line.length()){
				if(line[i] == '!'){
					cout<<"\n";
					++i;
					continue;
				}
				sum = 0;
				while(isdigit(line[i])){
					sum += (int)(line[i++] - '0');
				}
				if(line[i] == 'b') line[i] = ' ';
				cout<<setw(sum)<<setfill(line[i++])<<"";
			}
			cout<<"\n";
		}while(getline(cin,line) && !line.empty());
	}
	return 0;
}
