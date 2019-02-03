#include <bits/stdc++.h>

using namespace std;

class SegmentedTree{
public:
	SegmentedTree(vector<int> &vec){
		this->values = vec;
		this->indexes.assign(vec.size()*4,0);
		build(1,0,vec.size()-1);
	}
	int getMaxValue(int i, int j){
		return values[getMaxValueIndex(1,0, values.size()-1,i,j)];
	}
private:
	vector<int> values,indexes;
	void build(int pos, int l, int r){
		if(l==r){
			indexes[pos] = l;
		}else{
			build(left(pos), l, (l+r)/2);
			build(right(pos), (l+r)/2+1, r);
			int p1 = indexes[left(pos)], p2 = indexes[right(pos)];
			indexes[pos] = values[p1]>=values[p2]?p1:p2;
		}
	}

	int getMaxValueIndex(int pos, int l, int r, int i, int j){
		if(i>r || j<l) return -1;
		if(l>=i && r<=j)return indexes[pos];
		int p1 = getMaxValueIndex(left(pos),l,(l+r)/2,i,j);
		int p2 = getMaxValueIndex(right(pos),(l+r)/2+1,r,i,j);
		if(p1==-1)return p2;
		if(p2==-1)return p1;
		return values[p1]>=values[p2]?p1:p2;
	}

	int left(int index){
		return index<<1;
	}

	int right(int index){
		return (index<<1)+1;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,val;
	vector<int> numbers;
	cin>>size;
	for(int x=0; x<size && cin>>val; x++)numbers.push_back(val);
	SegmentedTree st(numbers);
	int cont = 0;
	for(int i=0; i<numbers.size()-1; i++){
		for(int j=i+1; j<numbers.size(); j++){
			long long multi = (long long)numbers[i]*(long long)numbers[j];
			if(multi<=(long long)(st.getMaxValue(i,j)))++cont;
			//cout<<i+1<<" - "<<j+1<<" max values is: "<<st.getMaxValue(i,j)<<" multiplication is "<<multi<<endl;
		}
	}
	cout<<cont<<'\n';
	return 0;
}