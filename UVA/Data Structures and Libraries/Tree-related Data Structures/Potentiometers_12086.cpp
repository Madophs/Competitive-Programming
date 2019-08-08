#include <bits/stdc++.h>

using namespace std;

class SegmentedTree{
	public:
		SegmentedTree(){
			this->tree.assign(200005<<1,0);
		}
		bool insertValues(){
			cin>>arraySize;
			if(!arraySize) return false;
			int limit = arraySize<<1;
			for(int i = arraySize; i < limit; i++) cin>>tree[i];
			tree[arraySize<<1] = 0;
			build();
			return true;	
		}
		void build(){
			for(int parent = arraySize-1; parent > 0; parent--)
				tree[parent] = tree[parent<<1] + tree[parent<<1|1];
		}
		int sumRange(int l, int r){
			int sum = 0;
			for(l += arraySize-1, r += arraySize; l < r; l>>=1, r>>=1){
				if(l&1) sum += tree[l++];
				if(r&1) sum += tree[--r];
			}	
			return sum;
		}
		void update(int index, int value){
			for(tree[index += arraySize-1] = value; index > 1; index>>=1)
				tree[index>>1] = tree[index^1] + tree[index];
		}
	private:
		vector<int> tree;
		int arraySize;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	SegmentedTree tree;
	string ins;
	int x, y;
	for(int c = 1; tree.insertValues(); c++){
		if(c > 1) cout<<"\n";
		cout<<"Case "<<c<<":\n";
		while(cin>>ins && ins != "END"){
			cin>>x>>y;
			if(ins == "M"){
				cout<<tree.sumRange(x, y)<<"\n";
			}else{
				tree.update(x,y);
			}
		}
	}
	return 0;
}

/*
// Typical recursive implementation
#include <bits/stdc++.h>

using namespace std;

class SegmentedTree{
	public:
		void insertInitialValues(int numberOfValues){
			int value;
			valuesVec.clear(), tree.clear();
			tree.assign(4*numberOfValues,0);
			valuesVec.emplace_back(0);
			while(numberOfValues-- && cin>>value) valuesVec.emplace_back(value);
			buildTree(1, valuesVec.size()-1);
		}

		void buildTree(int l, int r, int parent = 1){
			if(l==r){
				tree[parent] = valuesVec[l];
			}else{
				int leftChild = parent<<1;
				int rightChild = (parent<<1)+1;
				buildTree(l, (l+r)/2, leftChild);
				buildTree((l+r)/2+1, r, rightChild);
				tree[parent] = tree[leftChild] + tree[rightChild];
			}
		}
		int rangeSum(int i, int j){
			if(i == 1 && j == valuesVec.size()-1) return tree[1];
			return rangeSum(i, j, 1, valuesVec.size()-1);
		}
		int rangeSum(int &i, int &j, int l, int r, int parent = 1){
			if(r < i || l > j) return 0;
			if(l >= i && j >= r) return tree[parent];
			int leftChild = parent<<1;
			int rightChild = (parent<<1)+1;
			int leftResult = rangeSum(i, j, l, (l+r)/2, leftChild);
			int rightResult = rangeSum(i, j, (l+r)/2+1, r, rightChild);
			return leftResult + rightResult;
		}
		
		void update(int &index, int &value){
			update(index, value, 1, valuesVec.size()-1, 1);
		}

		void update(int &index, int &value, int l, int r, int parent){
			if(l == r){
				if(l == index) tree[parent] = value;
				return;
			}
			int leftChild = parent<<1;
			int rightChild = (parent<<1)+1;
			if(index <= (l+r)/2) update(index, value, l, (l+r)/2, leftChild);
			if(index > (l+r)/2) update(index, value, (l+r)/2+1, r, rightChild);
			tree[parent] = tree[leftChild] + tree[rightChild];
		}
	private:
		vector<int> valuesVec, tree;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numberOfValues, index, value, i, j;
	string ins;
	SegmentedTree potentiometers;
	for(int c = 1; cin>>numberOfValues && numberOfValues; c++){
		if(c > 1) cout<<"\n";
		potentiometers.insertInitialValues(numberOfValues);
		cout<<"Case "<<c<<":\n";
		while(cin>>ins && ins != "END"){
			if(ins == "M"){
				cin>>i>>j;
				cout<<potentiometers.rangeSum(i,j)<<"\n";
			}else{
				cin>>index>>value;
				potentiometers.update(index, value);
			}
		}
	}
	return 0;
}
*/

