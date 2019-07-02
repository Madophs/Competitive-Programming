#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string linea;
	while(getline(cin,linea)){
		bool encadenadas = true;
		stringstream ss(linea);
		string anterior = "", actual = "";
		for(int i = 0; getline(ss,actual,' '); ++i){
			if(i){
				if(anterior.back() != actual.at(1) || anterior.at(anterior.length()-2) != actual.front()){
					encadenadas = false;
					break;
				}
			}
			anterior = actual;
		}
		cout<<(encadenadas ? "SI\n" : "NO\n");
	}	
	return 0;
}
