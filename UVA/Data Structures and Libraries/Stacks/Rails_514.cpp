#include <bits/stdc++.h>

using namespace std;

bool canBeOrdered(queue<int> trainOrder, queue<int> orderOutput){
	stack<int> station;
	while(!trainOrder.empty() && !orderOutput.empty()){
		station.emplace(trainOrder.front());
		trainOrder.pop();
		while((!station.empty() && !orderOutput.empty()) && station.top() == orderOutput.front()){
			station.pop();
			orderOutput.pop();
		}
	}
	if(!station.empty() || !orderOutput.empty() || !trainOrder.empty()) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size, val;
	while(cin>>size && size){
		queue<int> trainOrder;
		for(int i = 1; i<=size; i++) trainOrder.push(i);
		while(true){
			queue<int> order;
			for(int i = 0; i<size && cin>>val && val; i++) order.push(val);
			if(!val) break;
			cout<<(canBeOrdered(trainOrder, order)?"Yes\n":"No\n");
		}
		cout<<"\n";
	}
	return 0;
}