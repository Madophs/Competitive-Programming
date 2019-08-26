#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

enum Sign{
	Positive, Negative, Zero, Null
};

class SegmentedTree {
	public:
		SegmentedTree(){
			this->tree.assign(MAX_N, Zero);
		}

		void insertElements(int numElements){
			this->size = numElements;
			int element, limit = size << 1;
			for(int i = size; i < limit; i++){
				cin>>element;
				Sign sign = getSign(element);
				tree[i] = sign;
			}
			build();
		}

		void build(){
			for(int parent = size-1; parent > 0; --parent){
				tree[parent] = getSignProduct(tree[parent<<1], tree[parent<<1^1]);
			}
		}

		void change(int index, int value){
			tree[index += (size-1)] = getSign(value);
			for(int parent = index >> 1; parent > 0; parent >>= 1){
				tree[parent] = getSignProduct(tree[parent<<1], tree[parent<<1^1]);
			}
		}

		char product(int l, int r){
			Sign sign = Null;
			for(l += size-1, r += size; l < r; l>>=1, r>>=1){
				if(l&1){
					if(sign == Null){
						sign = tree[l++];
					}else{
						sign = getSignProduct(sign, tree[l++]);
					}
				}
				if(r&1){
					if(sign == Null){
						sign = tree[--r];
					}else{
						sign = getSignProduct(sign, tree[--r]);
					}
				}
			}
			if(sign == Zero) return '0';
			if(sign == Positive) return '+';
			return '-';
		}
		void print(){
			int limit = size << 1;
			for(int i = 0; i < limit; i++){
				if(tree[i] == Positive){
					cout<<"+ ";
				}else if(tree[i] == Negative){
					cout<<"- ";
				}else{
					cout<<"0 ";
				}
			}
			cout<<endl;
		}
	private:
		vector<Sign> tree;
		int size;
		Sign getSign(int value){
			if(value < 0) return Negative;
			if(value > 0) return Positive;
			return Zero;
		}
		Sign getSignProduct(Sign sign1, Sign sign2){
			if(sign1 == Zero || sign2 == Zero) return Zero;
			if(sign1 == sign2) return Positive;
			return Negative;
		}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int rounds, elements, i, j;
	char command;
	SegmentedTree tree;
	while(cin>>elements>>rounds){
		tree.insertElements(elements);
		while(rounds-- && cin>>command>>i>>j){
			if(command == 'C'){
				tree.change(i, j);
			}else{
				cout<<tree.product(i, j);
			}
		}
		cout<<"\n";
	}
	return 0;
}
