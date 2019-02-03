#include <bits/stdc++.h>

using namespace std;

int getMaxValue(stack<int> &pila){
	stack<int> temp = pila;
	int maxValue= 1;
	while(!temp.empty()){
		maxValue = max(maxValue,temp.top());
		temp.pop();
	}
	return maxValue;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q,op,val, maxValue=0;
	stack<int> pila;
	cin>>q;
	while(q--){
		cin>>op;
		switch(op){
			case 1:
				cin>>val;
				pila.push(val);
				maxValue = max(maxValue,val);
				break;
			case 2:
				maxValue = pila.top()==maxValue? 0: maxValue;
				pila.pop();
				if(maxValue==0){
					maxValue = getMaxValue(pila);
				}
				break;
			case 3:
				if(maxValue==0){
					maxValue = getMaxValue(pila);
				}
				cout<<maxValue<<endl;
				break;
			case 4:
				cout<<pila.top()<<endl;
				break;
		}
	}	
	return 0;
}