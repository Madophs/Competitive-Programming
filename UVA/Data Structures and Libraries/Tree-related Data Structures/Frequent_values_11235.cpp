#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 200010;

class SegmentedTree{
	public:
		SegmentedTree(){
			tree.assign(MAX_SIZE, 0);
		}

		void insertValues(int length){
			this->size = length;
			values.resize(size);
			int currentValue, prevValue = (int)1e9;
			for(int i = 0, f = 0; i < size; i++){
				cin>>currentValue;
				if(prevValue == currentValue){
					values[i].first = tree[i+size] = ++f;
				}else{
					values[i].first = tree[i+size] = f = 1;
					invertValues(i-1);
				}
				prevValue = currentValue;
			}
			invertValues(size-1);
			build();
		}
	
		void build(){
			for(int parent = size-1; parent > 0; parent--){
				tree[parent] = max(tree[parent<<1^1], tree[parent<<1]);
			}
		}

		void invertValues(int index){
			if(index < 0) return;
			int frequency = values[index].first; 
			for(index -= (frequency-1); frequency > 0; index++){
				values[index].second = frequency--;
			}
		}
		
		int mostFrequentValue(int i, int j){
			--i, --j;
			if(i + (values[i].second-1) >= j){
				return (j - i)+1;
			}
			int result = values[i].second;
			i += result;
			for(i += size, j += size+1; i < j; i>>= 1, j>>=1){
				if(i&1) result = max(result, tree[i++]);
				if(j&1) result = max(result, tree[--j]);
			}
			return result;
		}
	private:
		vector<int> tree;
		vector<pair<int,int>> values;
		int size;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size, queries, i, j;
	SegmentedTree tree;
	while(cin>>size && size && cin>>queries){
		tree.insertValues(size);
		while(queries-- && cin>>i>>j){
			cout<<tree.mostFrequentValue(i, j)<<"\n";
		}
	}
	return 0;
}
