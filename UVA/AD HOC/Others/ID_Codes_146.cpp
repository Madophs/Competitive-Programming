#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string code;
	while(cin>>code && code!="#"){
		if(next_permutation(code.begin(), code.end())){
			cout<<code<<endl;
		}else{
			cout<<"No Successor\n";
		}
	}
	return 0;
}
