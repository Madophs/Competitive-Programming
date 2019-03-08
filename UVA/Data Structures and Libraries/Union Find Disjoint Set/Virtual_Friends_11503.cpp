#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
	UnionFind(int relationships){
		relationships<<=1;
		for(int i = 0;i<relationships; i++) parent.push_back(i);
		rank.assign(relationships,0), netSize.assign(relationships,1);
		index = 0;
	}
	int networkSize(string n1){
		int a = people.find(n1)->second;
		return netSize[findParent(a)];
	}
	void connect(string n1, string n2){
		if(people.find(n1) == people.end()) people[n1] = index++;
		if(people.find(n2) == people.end()) people[n2] = index++;
		int a = people.find(n1)->second, b = people.find(n2)->second;
		connect(a,b);
	}
private:
	unordered_map<string,int> people;
	vector<int> parent, rank, netSize;
	int index;
	int findParent(int node){
		if(node == parent[node]) return node;
		return findParent(parent[node]);
	}
	void connect(int a, int b){
		int x = findParent(a), y = findParent(b);
		if(x!=y){
			if(rank[x] > rank[y]){
				parent[y] = x;
				netSize[x]+=netSize[y];
			}else{
				parent[x] = y;
				netSize[y] += netSize[x];
				if(rank[x] == rank[y]) ++rank[y];
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, relations;
	string name1, name2;
	cin>>tests;
	while(tests-- && cin>>relations){
		UnionFind uf(relations);
		while(relations-- && cin>>name1>>name2){
			uf.connect(name1, name2);
			cout<<uf.networkSize(name1)<<'\n';
		}
	}
	return 0;
}