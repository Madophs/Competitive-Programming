#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ladies, chimps, height;
	cin>>ladies;
	vector<int> ladiesHeights;
	while(ladies-- && cin>>height) ladiesHeights.push_back(height);
	cin>>chimps;
	while(chimps-- && cin>>height){
		int shorter = lower_bound(ladiesHeights.begin(), ladiesHeights.end(),height) - ladiesHeights.begin();
		int taller = upper_bound(ladiesHeights.begin(), ladiesHeights.end(), height) - ladiesHeights.begin();
		if(ladiesHeights[shorter] == height && shorter--){
			cout<<ladiesHeights[shorter]<<" ";
		}else{
			if(shorter <= 0){
				cout<<"X ";
			}else{
				cout<<ladiesHeights[--shorter]<<" ";
			}
		}
		if(taller != ladiesHeights.size()){
			cout<<ladiesHeights[taller]<<"\n";
		}else{
			cout<<"X\n";
		}
	}
	return 0;
}