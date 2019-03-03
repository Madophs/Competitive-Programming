#include <bits/stdc++.h>

using namespace std;

class UnionFind{

public:
	UnionFind(int tam){
		for(int x=0; x<=tam; x++)this->parent.push_back(x);

		this->rank.assign(tam+1,0);
	}
	int findSet(int v){
		if(v==parent[v]){
			return v;
		}else{
			v=findSet(parent[v]);
		}
		return v;
	}
	bool sameSet(int v1, int v2){
		int p1=findSet(v1),p2=findSet(v2);
		if(p1==p2)return true;
		return false;

	}
	void setUnion(int v1, int v2){
		int p1=findSet(v1),p2=findSet(v2);
		if(p1!=p2){
			if(rank[p1]>rank[p2]){
				parent[p2]=p1;
			}else{
				parent[p1]=p2;
				if(rank[p1]==rank[p2])++rank[p2];
			}
		}
	}
private:
	vector<int> parent,rank;
};
int main(){
	ios::sync_with_stdio(false);
	int t,vertex,wrong,right;cin>>t;
	string line;
	bool salto=false;
	while(t--){
		if(salto)cout<<"\n";
		salto=true;
		cin>>vertex;
		UnionFind uf(vertex);
		wrong=right=0;
		cin.ignore();
		while(getline(cin,line) && !line.empty()){
			stringstream tk(line);
			string instruction;
			int v1,v2;
			tk>>instruction;
			tk>>v1;
			tk>>v2;
			if(instruction=="c"){
				uf.setUnion(v1,v2);
			}else{
				bool temp=uf.sameSet(v1,v2);
				if(temp){
					++right;
				}else{
					++wrong;
				}
			}
		}
		cout<<right<<","<<wrong<<"\n";
	}
	return 0;
}
