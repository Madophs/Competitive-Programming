#include <bits/stdc++.h>

using namespace std;

void swapping(string &str, int i, int j, int length){
	for(int x=0; x<length/2; x++) swap(str[x+i],str[j-1-x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length, i,j;
	string line;
	while(cin>>length && length){
		cin>>line;
		length = line.length()/length;
		i = 0, j = length;
		while(j<=line.length()){
			swapping(line, i, j,length);
			i+=length, j+=length;
		}
		cout<<line<<'\n';
	}
	return 0;
}