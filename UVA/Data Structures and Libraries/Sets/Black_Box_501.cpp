#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sets,m,n,value;
	cin>>sets;
	for(int s = 0; s<sets; s++){
		if(s)cout<<'\n';
		cin>>m>>n;
		vector<int> transPut(m,0), transGet;
		for(int i = 0;i<m && cin>>transPut[i]; i++);
		for(int i = 0;i<n && cin>>value; i++) transGet.push_back(value);
		int index = 0;
		for(int i = 0;i<transGet.size(); i++){
			nth_element(transPut.begin(),transPut.begin()+index,transPut.begin()+transGet[i]);
			cout<<transPut[index++]<<"\n";
		}
	}
	return 0;
}