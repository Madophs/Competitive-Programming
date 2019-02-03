#include <bits/stdc++.h>

using namespace std;

int removeIndexAt(string &str){
	int i = 0, j = str.length()-1,index = -1, mismatches = 0;
	int x = 0, y = str.length()-1,index2 = -1, mismatches2 = 0;
	while(i<=j || x<=y){
		if(i<=j){
			if(str[i] == str[j]){
				++i,--j;
			}else{
				if(i+1 <= j && str[i+1] == str[j]){
					++mismatches,index = i,++i;
				}else if(j-1 >= i && str[j-1] == str[i]){
					++mismatches,index = j,--j;
				}else{
					++mismatches,++i,--j;
				}
			}
		}
		if(x<=y){
			if(str[x] == str[y]){
				++x,--y;
			}else{
				if(y-1 >= x && str[y-1] == str[x]){
					++mismatches2,index2 = y,--y;
				}else if(x+1 <= y && str[x+1] == str[y]){
					++mismatches2,index2 = x,++y;
				}else{
					++mismatches2,++x,--y;
				}
			}
		}
	}
	if(mismatches == 1)return index;
	if(mismatches2 == 1)return index2;
	return -1;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	string str;
	cin>>q;
	while(q-- && cin>>str){
		cout<<removeIndexAt(str)<<endl;
	}
	return 0;
}