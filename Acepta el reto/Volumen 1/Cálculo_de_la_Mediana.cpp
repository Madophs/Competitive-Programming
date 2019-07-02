#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cantNumeros, numero, res;
	while(cin>>cantNumeros && cantNumeros){
		vector<int> numerosVec;
		while(cantNumeros-- && cin>>numero) numerosVec.emplace_back(numero);
		sort(numerosVec.begin(), numerosVec.end());
		if((int)numerosVec.size() & 1){
			res = numerosVec[numerosVec.size()/2] * 2;
		}else{
			res = (numerosVec[numerosVec.size()/2] + numerosVec[numerosVec.size()/2-1]);
		}
		cout<<res<<"\n";
	}	
	return 0;
}
