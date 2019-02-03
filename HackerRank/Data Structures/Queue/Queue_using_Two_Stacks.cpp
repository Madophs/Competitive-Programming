#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> stacks;
	int q,val,op;
	cin>>q;
	while(q--){
		cin>>op;
		switch (op){
			case 1:
				cin>>val;
				stacks.push_back(val);
				break;
			case 2:
				stacks.pop_front();
				break;
			case 3:
				cout<<stacks.front()<<endl;
				break;
		}
	}	
	return 0;
}