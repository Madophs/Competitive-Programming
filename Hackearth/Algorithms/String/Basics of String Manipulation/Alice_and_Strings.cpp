#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin>>A>>B;
	if(A.length() != B.length()){
		cout<<"NO\n";
	}else{
		int currDiff = 0, prevDiff = (int)1e9;
		bool compatible = true;
		for(int i = 0; i < A.length() && compatible; ++i){
			currDiff = (int)(B[i]-A[i]);
		       	if(currDiff < 0){
				compatible = false;
			}else if(currDiff > prevDiff){
				compatible = false;
			}
			prevDiff = currDiff;
		}
		cout<<(compatible ? "YES\n" : "NO\n");
	}
	return 0;
}
