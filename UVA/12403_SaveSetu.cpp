#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;

int main(){
	int tc,suma=0;
	string cadena;
	cin>>tc;
	cin.ignore();
	while(tc--){
		getline(cin,cadena);
		if(cadena[0]=='d'){
			string basura;
			int val;
			stringstream tk(cadena);
			tk>>basura;
			tk>>val;
			suma+=val;
		}else{
			cout<<suma<<"\n";
		}
	}
	return 0;
}
