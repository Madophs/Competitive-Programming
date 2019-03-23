#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int deckSize;
	while(cin>>deckSize && deckSize){
		deque<int> q;
		for(int i = deckSize; i>0; i--) q.emplace_back(i);
		cout<<"Discarded cards:";
		int popped, colon = 0;
		while(q.size()>1){
			if(colon++)cout<<",";
			popped = q.back();
			q.pop_back();
			q.emplace_front(q.back());
			q.pop_back();
			cout<<" "<<popped;
		}
		cout<<"\nRemaining card: "<<q.back()<<"\n";
	}
	return 0;
}