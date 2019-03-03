#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int queries, op, value;
	while(cin>>queries){
		priority_queue<int, vector<int>, less<int> > pq;
		queue<int> q;
		stack<int> s;
		bitset<3> possibles;
		possibles.set();
		while(queries-- && cin>>op>>value){
			if(op&1){
				if(possibles.test(0)) pq.push(value);
				if(possibles.test(1)) q.push(value);
				if(possibles.test(2)) s.push(value);
			}else{
				if(possibles.test(0)){
					if(pq.empty()){
						possibles.reset();
						continue;
					}
					if(value != pq.top()){
						possibles.reset(0);
					}else{
						pq.pop();
					}
				}
				if(possibles.test(1)){
					if(s.empty()){
						possibles.reset();
						continue;
					}
					if(value != q.front()){
						possibles.reset(1);
					}else{
						q.pop();
					}
				}
				if(possibles.test(2)){
					if(s.empty()){
						possibles.reset();
						continue;
					}
					if(value != s.top()){
						possibles.reset(2);
					}else{
						s.pop();
					}
				}
			}
		}
		if(possibles.count() > 1){
			cout<<"not sure\n";
		}else if(possibles.count() == 0){
			cout<<"impossible\n";
		}else if(possibles.test(0)){
			cout<<"priority queue\n";
		}else if(possibles.test(1)){
			cout<<"queue\n";
		}else{
			cout<<"stack\n";
		}
	}
	return 0;
}