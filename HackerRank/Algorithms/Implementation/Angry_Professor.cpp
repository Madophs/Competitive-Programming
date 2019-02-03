#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t,students,threshold,arrival,early;
	cin>>t;
	while(t--){
		cin>>students>>threshold;
		early = 0;
		while(students--){
			cin>>arrival;
			if(arrival<=0){
				++early;
			}
		}
		cout<<((early>=threshold)?"NO\n":"YES\n");
	}
	
	return 0;
}