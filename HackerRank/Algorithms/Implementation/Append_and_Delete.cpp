#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	int k,similar=0,dif=0;
	cin>>a>>b>>k;
	for(auto i = a.begin(), j = b.begin(); i!=a.end() && j!=b.end(); i++,j++){
		if(*i!=*j)break;
		++similar;
	}
	dif = (a.length()-similar)+(b.length()-similar);
	if(a.length()+b.length() <= k)dif = k;
	if(dif!=k && dif < k && ((dif%2==0 && k%2==0) || (dif&1 && k&1) )) dif = k;
	cout<<(dif==k?"Yes\n":"No\n");
	return 0;
}