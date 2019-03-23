#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int front, rear;
	double val;
	while(cin>>front && front && cin>>rear){
		vector<double> frontTeeth, rearTeeth;
		while(front-- && cin>>val) frontTeeth.emplace_back(val);
		while(rear-- && cin>>val) rearTeeth.emplace_back(val);
		double ans = 0;
		vector<double> values;
		for(int i = 0; i<frontTeeth.size(); i++){
			for(int j = 0; j<rearTeeth.size(); j++){
				values.emplace_back(rearTeeth[j]/frontTeeth[i]);
			}
		}
		sort(values.begin(), values.end());
		for(int x = 0; x<values.size()-1; x++){
			ans = fmax(ans,values[x+1]/values[x]);
		}
		cout<<fixed<<setprecision(2)<<ans<<"\n";
	}
	return 0;
}