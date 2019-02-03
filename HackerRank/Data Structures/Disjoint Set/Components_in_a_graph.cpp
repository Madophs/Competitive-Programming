#include <bits/stdc++.h>

using namespace std;

class DisjointSet{

public:
	DisjointSet(int size){
		++size;
		this->rank.assign(size,0);
		this->set_size.assign(size,1);
		for(int x=0; x<size; x++)this->parent.push_back(x);
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
			if(rank[x]>y){
				parent[y] = x;
				set_size[x]+=set_size[y];
				set_size[y] = set_size[x];
			}else{
				parent[x] = y;
				set_size[y]+=set_size[x];
				set_size[x] = set_size[y];
				if(rank[y]==rank[x]) ++rank[y];
			}
		}
	}

	vector<int> getMinMax(){
		vector<int> temp;
		int minValue = 1e9, maxValue = 2;
		updateSizes();
		for(auto iter = set_size.begin(); iter!=set_size.end(); iter++){
			maxValue = max(maxValue,*iter);
			if(*iter>1)minValue = min(minValue,*iter);
		}
		temp.push_back(minValue),temp.push_back(maxValue);
		return temp;
	}
private:
	void updateSizes(){
		for(int x=0; x<set_size.size(); x++){
			set_size[x] = max(set_size[x], set_size[findSet(x)]);
		}
	}
	vector<int> rank,parent,set_size;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n;
	DisjointSet ds(n<<1);
	while(n--){
		cin>>a>>b;
		ds.connect(a,b);
	}
	vector<int> ans = ds.getMinMax();
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}