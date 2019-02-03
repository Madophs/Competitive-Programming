#include <bits/stdc++.h>

using namespace std;

void slidingWindow(vector<int> &vec, int &k){
	deque<int> q;
	int x = 0;
	for(; x<k; x++){
		while(!q.empty() && vec[q.back()] < vec[x])q.pop_back();
		q.push_back(x);
	}
	for(; x<vec.size(); x++){
		cout<<vec[q.front()]<<" ";
		while(!q.empty() && q.front() <= x-k)q.pop_front();
		while(!q.empty() && vec[q.back()] < vec[x])q.pop_back();
		q.push_back(x);
	}
	cout<<vec[q.front()]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,k,val;
	cin>>t;
	while(t-- && cin>>n>>k){
		vector<int> num;
		while(n-- && cin>>val)num.push_back(val);
		slidingWindow(num,k);
	}
	return 0;
}