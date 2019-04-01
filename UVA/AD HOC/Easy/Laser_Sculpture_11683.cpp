#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int height, length, ans, layer;
	while(cin>>height && height && cin>>length){
		 ans = 0, layer = height;
		vector<int> values(length);
		for(int i = 0; i<values.size() && cin>>values[i]; i++){
			if(layer > values[i]){
				ans += layer-values[i];
				layer = values[i];
			}else if(layer < values[i]){
				layer = values[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}