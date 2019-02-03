#include <bits/stdc++.h>

using namespace std;

int count(string str, int length){
	vector<int> z(str.size());
	int l = 0, r = 0, k, count = 0;
	for(int i = 1; i<str.size(); i++){
		if(i > r){
			l = r = i;
			while(r < str.size() && str[r-l] == str[r])++r;
			z[i] = r-l;
			if(z[i] == length)++count;
			--r;
		}else{
			k = i-l;
			if(z[k] < r-i+1){
				z[i] = z[k];
			}else{
				l = i;
				while(r < str.size() && str[r-l] == str[r])++r;
				z[i] = r-l;
				if(z[i] == length) ++count;
				--r;
			}
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string pattern,text;
	cin>>pattern>>text;
	cout<<count(pattern+"$"+text,pattern.size())<<'\n';
	return 0;
}