#include <bits/stdc++.h>

using namespace std;

int getMinMax(vector<int> &vec, int &d){
	deque<int> q;
	int minValue = 1e9;
	for(int x=0; x<d; x++){
		while(!q.empty() && vec[x]>=vec[q.back()]) q.pop_back();
		q.push_back(x);
	}
	for(int x=d; x<vec.size(); x++){
		minValue=min(minValue,vec[q.front()]);
		while(!q.empty() && q.front()<=x-d) q.pop_front();
		while(!q.empty() && vec[x]>=vec[q.back()]) q.pop_back();
		q.push_back(x);
	}
	return min(minValue,vec[q.front()]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,d,val,minValue=1e9,maxValue=-1;
	vector<int> vec;
	cin>>n>>q;
	while(n-->0 && cin>>val){
		vec.push_back(val);
		minValue = min(minValue,val);
		maxValue = max(maxValue,val);
	}
	while(q-- && cin>>d){

		if(d==1){
			cout<<minValue<<endl;
		}else if(d==vec.size()){
			cout<<maxValue<<endl;
		}else{
			cout<<getMinMax(vec,d)<<endl;
		}
	}
	return 0;
}
