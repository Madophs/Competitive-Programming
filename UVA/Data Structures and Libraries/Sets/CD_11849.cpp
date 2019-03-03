#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,disc;
	set<int> jack,jill;
	while(cin>>a>>b && (a || b)){
		jack.clear(), jill.clear();
		while(a-- && cin>>disc) jack.insert(disc);
		while(b-- && cin>>disc) if(jack.find(disc) != jack.end()) jill.insert(disc);
		cout<<jill.size()<<'\n';
	}
	return 0;
}