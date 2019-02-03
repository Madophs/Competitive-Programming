#include <bits/stdc++.h>
#define LSOne(n) n&-n

using namespace std;

class FenwickTree{
private:
	vector<int> frec;
	int size;
public:
	FenwickTree(int size){
		this->frec.assign(size,0);
		this->size = size;
	}

	void adjust(int index, int val,bool b = false){
		if(b)val = val-rsq(index, index);
		for(; index<size; index+=LSOne(index)) frec[index]+=val;
	}

	int rsq(int index){
		int sum = 0;
		for(; index; index-=LSOne(index)) sum+=frec[index];
		return sum;
	}

	int rsq(int i,int j){
		return rsq(j)-(i==0? 0: rsq(i-1));
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,op,i,j,maxValue = -1e9;
	cin>>n;
	vector<int> vec(n,0);
	for(int x=0; x<n && cin>>vec[x]; x++)maxValue = max(maxValue,vec[x]);
	FenwickTree ft(maxValue*10);
	for(int x=0; x<n; x++) ft.adjust(x+1,vec[x]);
	cin>>q;
	while(q--){
		cin>>op>>i>>j;
		if(op){
			ft.adjust(i,j,true);
		}else{
			cout<<ft.rsq(i,j)<<endl;
		}
	}
	return 0;
}

/*
11
2 4 5 5 6 6 6 7 7 8 9
10
0 1 6
0 4 6
*/