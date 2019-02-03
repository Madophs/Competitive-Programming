#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> vec(n,0);
	for(int x=0; x<vec.size(); x++)cin>>vec[x];
	for(auto iter = vec.rbegin(); iter!=vec.rend(); iter++){
		if(iter!=vec.rbegin())cout<<" ";
		cout<<*iter;
	}
	cout<<endl;
	return 0;
}