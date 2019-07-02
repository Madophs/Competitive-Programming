#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int molinos, consultas, energia, i, j;
	unsigned int molinosArray[(int)1e6];
	unsigned int energiaTotal;
	molinosArray[0] = 0;
	while(cin>>molinos && molinos){
		for(int i = 1; i <= molinos && cin>>energia; i++)
			molinosArray[i] = molinosArray[i-1] + energia;
		cin>>consultas;
		while(consultas-- && cin>>i>>j){
			energiaTotal = molinosArray[j] - molinosArray[i-1];
			cout<<energiaTotal<<"\n";
		}
	}
	return 0;
}
