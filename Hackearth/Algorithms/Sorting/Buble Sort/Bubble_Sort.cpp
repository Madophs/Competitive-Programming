#include <bits/stdc++.h>

using namespace std;

int bubbleSort(vector<int> &vec){
	int count = 0;
	for(int x=0; x<vec.size()-1; x++){
		for(int y=0; y<vec.size()-1; y++){
			if(vec[y] > vec[y+1]){
				swap(vec[y],vec[y+1]);
				++count;
			}
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val;
	vector<int> numbers;
	cin>>n;
	for(int x=0; x<n && cin>>val; x++)numbers.push_back(val);
	int ans = bubbleSort(numbers);
	//for(auto it = numbers.begin(); it!=numbers.end(); it++)cout<<*it<<" ";
	//cout<<'\n';
	cout<<ans<<'\n';
	return 0;
}