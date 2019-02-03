#include <bits/stdc++.h>

using namespace std;

int countAs(string &s){
	int sum=0;
	for(auto iter = s.begin(); iter!=s.end(); iter++)
		if(*iter=='a')++sum;
	return sum;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	long long n,ans=0;
	cin>>s>>n;
	int as = countAs(s);
	ans = (n/(long long)(s.length()))*as;
	for(int x=0; x<n%s.length(); x++)
		if(s[x]=='a')++ans;
	cout<<ans<<endl;
	return 0;
}