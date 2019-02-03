#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int  n,val,avg,ans,set=0;
	vector<int> vec;
	while(cin>>n && n){
		avg=ans=0;
		while(n-- && cin>>val){
			vec.push_back(val);
			avg+=val;
		}
		avg/=vec.size();
		for(int x=0; x<vec.size(); x++){
			if(vec[x]<avg)ans+=abs(vec[x]-avg);
		}
		vec.clear();
		cout<<"Set #"<<++set<<"\n";
		cout<<"The minimum number of moves is "<<ans<<".\n\n";
	}	
	return 0;
}