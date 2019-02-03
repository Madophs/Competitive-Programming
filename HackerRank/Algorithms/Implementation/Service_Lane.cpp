#include <bits/stdc++.h>

using namespace std;

class SegmentedTree{
private:
	vector<int> tree,values;
	int right(int index){
		return (index<<1)+1;
	}
	int left(int index){
		return index<<1;
	}
	void build(int position, int l, int r){
		if(l==r){
			tree[position] = l;
		}else{
			build(left(position), l, (l+r)/2);
			build(right(position), ((l+r)/2)+1, r);
			int idx1 = tree[left(position)], idx2 = tree[right(position)];
			tree[position] = values[idx1] <= values[idx2]?idx1:idx2;
		}
	}
	int rmq(int pos, int l, int r, int i, int j){
		if(i > r || j < l) return -1;
		if(l>=i && r<=j) return tree[pos];
		int idx1 = rmq(left(pos), l,(l+r)/2,i,j);
		int idx2 = rmq(right(pos), ((l+r)/2)+1, r,i,j);
		if(idx1==-1)return idx2;
		if(idx2==-1)return idx1;
		return values[idx1] <= values[idx2]?idx1:idx2; 
	}
public:
	SegmentedTree(vector<int> &vec){
		values = vec;
		tree.assign(vec.size()*4,0);
		build(1,0,values.size()-1);
	}

	int rmq(int i, int j){
		return values[rmq(1,0,values.size()-1,i,j)];
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,i,j,val;
	vector<int> vec;
	cin>>n>>q;
	while(n-- && cin>>val)vec.push_back(val);
	SegmentedTree t(vec);
	while(q-- && cin>>i>>j)cout<<t.rmq(i,j)<<endl;
	return 0;
}