#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<string> pila;
	int q,op,val;
	string s;
	pila.push("");
	cin>>q;
	while(q-- && cin>>op){
		switch(op){
			case 1:
				cin>>s;
				pila.push(pila.top()+s);
			break;
			case 2:
				cin>>val;
				pila.push(pila.top().substr(0,pila.top().length()-val));
			break;
			case 3:
				cin>>val;
				cout<<pila.top().at(val-1)<<endl;
			break;
			case 4:
				pila.pop();
			break;
		}
	}	
	return 0;
}
