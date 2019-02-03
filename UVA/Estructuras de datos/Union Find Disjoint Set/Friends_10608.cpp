#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
	UnionFind(int tam){
		this->rank.assign(tam+1,0);
		this->size.assign(tam+1,1);
		for(int x=0; x<=tam;x++)this->parent.push_back(x);
	}
	int findSet(int v){
		return (parent[v]==v)?v:(parent[v]=findSet(parent[v]));
	}
	bool sameSet(int v1,int v2){
		int p1 = findSet(v1), p2=findSet(v2);
		if(p1==p2)return true;
		return false;
	}
	void setUnion(int v1, int v2){
		int x=findSet(v1),y=findSet(v2);
		if(x!=y){
			if(rank[x]>rank[y]){
				parent[y]=x;
				size[x]+=size[y];
			}else{
				parent[x]=y;
				size[y]+=size[x];
				if(rank[x]==rank[y])++rank[y];
			}
		}
	}
	int maxSet(){
		auto iter =max_element(size.begin(),size.end());
		return *iter;
	}
private:
	vector<int> rank,parent,size;
};
int main(){
	ios::sync_with_stdio(false);
	int t,friends,pairs;cin>>t;
	while(t--){
		cin>>friends>>pairs;
		int a,b;
		UnionFind fu(friends);
		while(pairs--){
			cin>>a>>b;
			fu.setUnion(a,b);
		}
		cout<<fu.maxSet()<<endl;
	}
	return 0;
}
