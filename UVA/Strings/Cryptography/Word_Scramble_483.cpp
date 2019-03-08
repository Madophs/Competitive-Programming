#include <bits/stdc++.h>

using namespace std;

void reverse(string &str, int i, int j){
	for(int index = 0; index<(j-i)/2; index++){
		swap(str[i+index],str[j-index-1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line,word;
	int i, j;
	while(getline(cin,line)){
		for(i = 0; i<line.length(); i++){
			if(line[i] == ' ') continue;
			for(j=i; j<line.length(); j++){
				if(line[j]==' ') break;
			}
			reverse(line,i,j);
			i = j;
		}
		cout<<line<<'\n';
	}
	return 0;
}