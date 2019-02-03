#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &vec, int steps=1e9){
	int index;
	for(int i = 0; i<vec.size()-1 && steps--; i++){
		index = i;
		for(int j = i+1;j < vec.size();j++){
			if(vec[index] > vec[j])
				index = j;
		}
		if(index!=i)
			swap(vec[index],vec[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,steps,val;
	vector<int> vec;
	cin>>size>>steps;
	for(int x=0; x<size && cin>>val; x++)vec.push_back(val);
	selectionSort(vec,steps);
	for(auto it = vec.begin(); it!=vec.end(); it++){
		if(it != vec.begin())cout<<" ";
		cout<<*it;
	}
	cout<<'\n';
	return 0;
}