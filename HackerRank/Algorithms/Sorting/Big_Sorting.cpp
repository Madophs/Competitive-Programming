#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,size;
	cin>>n;
	size = n;
	string arr[n];
	while(n-- && cin>>arr[n]);
	sort(arr,arr+size,[&](string a, string b){
		if(a.length() < b.length()) return true;
		if(a.length() == b.length()){
			for(int x=0; x<a.length(); x++){
				if(a[x]==b[x])continue;
				if(a[x] < b[x])return true;
				return false;
			}
		}
		return false;
	});
	for(int x=0; x<size; x++)cout<<arr[x]<<endl;
	return 0;
} 