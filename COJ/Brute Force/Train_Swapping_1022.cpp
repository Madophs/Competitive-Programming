#include <bits/stdc++.h>

using namespace std;

int insertionSort(vector<int> &vec){
	int swaps = 0, y;
	for(int x=1; x<vec.size(); x++){
		int value = vec[x];
		y = x-1;
		while(y>=0 && vec[y]>value){
			vec[y+1] = vec[y];
			vec[y] = value;
			--y,++swaps;
		}
	}
	return swaps;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,val;
	vector<int> vec;
	cin>>t;
	while(t-- && cin>>n){
		vec.clear();
		while(n-- && cin>>val) vec.push_back(val);
		cout<<"Optimal train swapping takes "<<insertionSort(vec)<<" swaps.\n";
	}	
	return 0;
}