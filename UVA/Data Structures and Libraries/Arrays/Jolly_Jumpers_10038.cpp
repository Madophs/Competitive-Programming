#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val;
	while(cin>>n){
		int ant = 1e9, current = 0, diff = 0;
		vector<bool> vec(n, false);
		vec[0] = true;
		for(int x=0; x<n && cin>>val; x++){
			current = val;
			diff = abs(current - ant);
			if(diff>0 && diff < vec.size()) vec[diff] = true;
			ant = current;
		}
		int i = 0;
		for(; i<vec.size() && vec[i]; i++);
		cout<<(i==vec.size()?"Jolly\n":"Not jolly\n");
	}
	return 0;
}
