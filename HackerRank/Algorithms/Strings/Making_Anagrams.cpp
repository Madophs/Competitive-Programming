#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	cin>>s1>>s2;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	int ans=0, x=0,i=0;
	while(x<s1.length() && i<s2.length()){
		if(s1[x]!=s2[i]){
			++ans;
			if(s1[x]<s2[i]){
				++x;
			}else{
				++i;
			}
		}else{
			++i,++x;
		}
	}
	while(i<s2.length())++ans,++i;
	while(x<s1.length())++ans,++x;
	cout<<ans<<endl;
	return 0;
}