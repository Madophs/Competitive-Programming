#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,size;
	cin>>n;
	size = n;
	int arr[n];
	while(n-- && cin>>arr[n]);
	sort(arr,arr+size);
	vector< pair<int,int> > pairs;
	int minDifference = 1e9;
	for(int x=0, j=1; j<size; x++,j++){
		if(minDifference > abs(arr[j]-arr[x])){
			minDifference = abs(arr[j]-arr[x]);
			pairs.clear();
			pairs.push_back(make_pair(arr[x], arr[j]));
		}else if(minDifference == abs(arr[j]-arr[x])){
			pairs.push_back(make_pair(arr[x], arr[j]));
		}
	}
	for(auto iter = pairs.begin(); iter!=pairs.end(); iter++)
		cout<<iter->first<<" "<<iter->second<<" ";
	cout<<endl;
	return 0;
}