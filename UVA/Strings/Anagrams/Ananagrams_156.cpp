#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> is;


int main() {
	unordered_map<string,is> mapa;
	string linea;
	while(cin>>linea){
		if(linea=="#")break;
		string aux=linea;
		for(int x=0; x<linea.length(); x++)linea[x]=tolower(linea.at(x));
		sort(linea.begin(), linea.end());
		auto iter = mapa.find(linea);
		if(iter==mapa.end()){
			mapa[linea]=is(0,aux);
		}else{
			mapa[linea].first++;
		}
	}
	vector<string> ananagrams;
	for (auto iter = mapa.begin(); iter != mapa.end(); iter++) {
		unordered_map<string, is>::reference ref = *iter;
		if (ref.second.first > 0)
			continue;
		ananagrams.push_back(ref.second.second);
	}
	sort(ananagrams.begin(), ananagrams.end());
	for (auto iter = ananagrams.begin(); iter != ananagrams.end(); iter++) {
		cout << *iter << "\n";
	}

    return 0;
}