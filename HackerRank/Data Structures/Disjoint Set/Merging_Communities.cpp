#include <bits/stdc++.h>

using namespace std;

class DisjointSet{

public:
	DisjointSet(int size){
		++size;
		this->community.assign(size,1);
		this->rank.assign(size,0);
		for(int x=0; x<size; x++)parent.push_back(x);
	}

	int findSet(int v){
		if(parent[v]==v)return v;
		return findSet(parent[v]);
	}

	bool sameSet(int v1, int v2){
		return findSet(v1)==findSet(v2);
	}

	void connect(int v1, int v2){
		if(!sameSet(v1,v2)){
			int x = findSet(v1), y = findSet(v2);
			if(rank[x]>rank[y]){
				parent[y] = x;
				community[x]+=community[y];
				community[y] = community[x];
			}else{
				parent[x] = y;
				community[y]+=community[x];
				community[x] = community[y];
				if(rank[y]==rank[x])++rank[y];
			}
		}
	}

	int getSize(int v1){
		return community[findSet(v1)];
	}
	
private:
	vector<int> rank,parent,community;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size,q,x,y;
	string type;
	cin>>size>>q;
	DisjointSet ds(size);
	while(q--){
		cin>>type;
		if(type=="Q"){
			cin>>x;
			cout<<ds.getSize(x)<<endl;
		}else{
			cin>>x>>y;
			ds.connect(x,y);
		}
	}
	return 0;
}
