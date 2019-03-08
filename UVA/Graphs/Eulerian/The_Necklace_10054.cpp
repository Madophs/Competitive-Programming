#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
	void connectBeads(int a, int b){
		unordered_multiset<int> temp;
		if(beads.find(a) == beads.end()) beads[a] = temp;
		if(beads.find(b) == beads.end()) beads[b] = temp;
		beads.find(a)->second.insert(b);
		beads.find(b)->second.insert(a);
	}
	void printBeads(){
		if(!isEulerian()){
			cout<<"some beads may be lost\n";
		}else{
			bitset<60> visited;
			stack<int> currentPath;
			vector<int> tour;
			currentPath.push(startingBead);
			int u = startingBead;
			while(!currentPath.empty()){
				visited.set(u);
				if(!beads.find(u)->second.empty()){
					int v = *beads.find(u)->second.begin();
					beads.find(u)->second.erase(beads.find(u)->second.find(v));
					beads.find(v)->second.erase(beads.find(v)->second.find(u));
					currentPath.push(v);
					u = v;
				}else{
					tour.push_back(u);
					currentPath.pop();
					if(currentPath.empty()) break;
					u = currentPath.top();
				}
			}
			if(visited.count()!=beads.size()){
				cout<<"some beads may be lost\n";
				return;
			}
			for(int x = 1; x<tour.size(); x++){
				cout<<tour[x-1]<<" "<<tour[x]<<"\n";
			}
		}
	}
	bool isEulerian(){
		startingBead = beads.begin()->first;
		for(auto u = beads.begin(); u!=beads.end(); u++){
			if(u->second.size()&1){
				return false;
			}
		}
		return true;
	}
	private:
	unordered_map<int, unordered_multiset<int> > beads;
	int startingBead;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, edges, a,b;
	cin>>tests;
	for(int t = 0; t<tests; t++){
		if(t) cout<<"\n";
		cin>>edges;
		Graph g;
		while(edges-- && cin>>a>>b) g.connectBeads(a,b);
		cout<<"Case #"<<t+1<<"\n";
		g.printBeads();
	}
	return 0;
}