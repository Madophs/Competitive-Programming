#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test,s1,s2;
	cin>>test;
	while(test--){
		cin>>s1>>s2;
		vector<int> vec1(s1,0), vec2(s2,0);
		while(s1-- && cin>>vec1[s1]);
		while(s2-- && cin>>vec2[s2]);
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		int i = 0, j = 0, equals = 0;
		while(i<vec1.size() && j<vec2.size()){
			if(vec1[i] == vec2[j]){
				++j,++i,++equals;
			}else if(vec1[i]<vec2[j]){
				++i;
			}else{
				++j;
			}
		}
		cout<<(vec1.size()+vec2.size()-(equals<<1))<<"\n";
	}	
	return 0;
}