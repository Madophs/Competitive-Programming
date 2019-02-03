#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,lastAnswer=0,op,x,y;
	cin>>n>>q;
	vector< vector<int> > seqList(n, vector<int>());
	while(q--){
		cin>>op>>x>>y;
		if(op==1){
			int index = (x xor lastAnswer) % n;
			seqList[index].push_back(y);
		}else{
			int index = (x xor lastAnswer) % n;
			lastAnswer = seqList[index][y%seqList[index].size()];
			cout<<lastAnswer<<endl;
		}
	}
	return 0;
}