#include <bits/stdc++.h>

using namespace std;


string convertToFormat(string &s){
	string newString = "|";
	for(auto c = s.begin(); c!=s.end(); c++) newString+="|",newString+=*c;
	newString+="|$";
	return newString;
}

void createPatternArray(string &s, int *&pattern, int *&results){
	string temp = convertToFormat(s);
	pattern = new int[temp.length()]();
	results = new int[s.length()]();
	int center = 0, r = 0,mirror;
	for(int i = 1; i<temp.length(); i++){
		mirror = center-(i - center);
		if(i < r){
			pattern[i] = min(r-i,pattern[mirror]);
		}
		while(temp[i-1-pattern[i]] == temp[i+1+pattern[i]])++pattern[i];
		if(i + pattern[i] > r){
			center = i, r = i+pattern[i];
		}
		results[i/2-1] = max(pattern[i],results[i/2-1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int *pattern,*results;
	string str;
	int q,i,length;
	cin>>str>>q;
	createPatternArray(str,pattern,results);
	while(q--){
		cin>>i>>length;
		int ans = 0;
		//for(int x = 0; x<str.size(); x++)cout<<results[x]<<" ";
		//cout<<endl;
		for(int index = i; index<str.length(); index++){
			if(results[index]>=length){
				if(results[index] & 1){
					if(index - (results[index]/2) == i){
						//++ans;
					}else{
					}
						int cutPalindrome = 2*(index-i)+1;
						if(cutPalindrome <= results[index] && cutPalindrome >= length)++ans;
				}else{
					if(index - ((results[index]-1)/2) == i){
						//++ans;
					}else{
						//cout<<cutPalindrome<<endl;
						//int cutPalindrome = 2*((index-1)-i)+1;
					}
						int cutPalindrome = 2*(index-i)+2;
						if(cutPalindrome <= results[index] && cutPalindrome >= length)++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}