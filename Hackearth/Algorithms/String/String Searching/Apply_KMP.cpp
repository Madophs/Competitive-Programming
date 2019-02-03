#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string &p){
	vector<int> vec(p.size()+1,0);
	vec[0] = -1;
	int i = 0, j = -1;
	while(i < p.length()){
		while(j>=0 && p[i]!=p[j]) j = vec[j];
		++j,++i;
		vec[i] = j;
	}
	return vec;
}

int countOcurrences(string &p, string &t, vector<int> &pattern){
	int i = 0, j = 0, count = 0;
	while(i < t.length()){
		while(j>=0 && t[i]!=p[j]) j = pattern[j];
		++j,++i;
		if(j == p.length()){
			++count;
			j = pattern[j];
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string p,t;
	cin>>p>>t;
	vector<int> pattern = kmp(p);
	cout<<countOcurrences(p,t,pattern)<<'\n';
	return 0;
}