#include <bits/stdc++.h>

using namespace std;

class SegmentedTree{
public:
	SegmentedTree(vector<int> &vec){
		this->values = vec;
		this->indexed.assign(4*vec.size(),0);
		this->size = vec.size();
		buildSegmentedTree(1,0,size-1);
	}

	int rmq(int i,int j){
		return rmq(1,0,size-1,i,j);
	}

	void updateIndex(int index, int val){
		values[index] = val;
		updateSegmentedTree(1,0,size-1,index);
	}
private:
	vector<int> values,indexed;
	int size;
	int left(int index){
		return index<<1;
	}
	int right(int index){
		return (index<<1)+1;
	}

	void buildSegmentedTree(int position, int l, int r){
		if(l==r){
			indexed[position] = r;
		}else{
			buildSegmentedTree(left(position), l,(l+r)/2);
			buildSegmentedTree(right(position), ((l+r)/2)+1, r);
			int idx1 = indexed[left(position)], idx2 = indexed[right(position)];
			indexed[position] = values[idx1]>=values[idx2]?idx1:idx2;
		}
	}
	int rmq(int position, int l, int r, int i, int j){
		if(i>r || j<l)return -1;
		if(l>=i && r<=j)return indexed[position];
		int idx1 = rmq(left(position), l, (l+r)/2,i,j);
		int idx2 = rmq(right(position),((l+r)/2)+1,r,i,j);
		if(idx1==-1) return idx2;
		if(idx2==-1) return idx1;
		return values[idx1]>=values[idx2]?idx1: idx2;
	}
	void updateSegmentedTree(int position, int l, int r, int index){
		if(l==r)return;
		int middle = (l+r)/2;
		if(index<=middle) updateSegmentedTree(left(position),l,middle,index);
		if(index>=middle+1) updateSegmentedTree(right(position),middle+1,r,index);
		int idx1 = indexed[left(position)],idx2 = indexed[right(position)];
		indexed[position] = values[idx1]>=values[idx2]?idx1:idx2;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n;
	vector<int> vec(n,0);
	for(int x=0; x<n; x++)cin>>vec[x];
	SegmentedTree st(vec);
	cin>>q;
	int op,i,j;
	while(q--){
		cin>>op>>i>>j;
		if(op){
			st.updateIndex(i,j);
		}else{
			cout<<st.rmq(i,j)<<endl;
		}
	}
	return 0;
}

/**

Test case:

7
18 17 13 19 15 11 20
1
0 4
*/
