#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val;
	cin>>n;
	int arr[n];
	stack<int> pila;
	for(int x=0; x<n && cin>>arr[x]; x++);
	int ans = 0;
	for(int x=0; x<n; x++){
		while(!pila.empty()){
			val = arr[x];
			int temp = val ^ pila.top();
			ans = max(ans,temp);
			if(val < pila.top()){
				pila.pop();
			}else{
				break;
			}
		}
		pila.push(arr[x]);
	}
	cout<<ans<<endl;
	return 0;
}