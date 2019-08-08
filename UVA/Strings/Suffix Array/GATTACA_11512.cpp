#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1005;	
int suffix[MAX_N], ranking[MAX_N], c[MAX_N], tempSuffix[MAX_N], tempRanking[MAX_N];
int lcp[MAX_N], plcp[MAX_N], phi[MAX_N];
int len;
char line[MAX_N];

void countingSort(int k){
	int i, maxi = max(300, len), sum;
	memset(c, 0, sizeof c);
	for(i = 0; i < len; ++i)
		c[(i + k < len ? ranking[i+k] : 0)]++;
	for(i = 0, sum = 0; i < maxi; ++i){
		int temp = c[i];
		c[i] = sum, sum += temp;
	}
	for(i = 0; i < len; ++i){
		tempSuffix[c[(suffix[i]+k < len ? ranking[suffix[i]+k] : 0)]++] = suffix[i];
	}
	for(i = 0; i < len; ++i) suffix[i] = tempSuffix[i];
}

void constructSA(){
	int i, r, k;
	for(int i = 0; i < len; ++i)
		suffix[i] = i, ranking[i] = line[i];
	for(k = 1; k < len; k<<=1){
		countingSort(k);
		countingSort(0);
		tempRanking[suffix[0]] = r = 0;
		for(i = 1; i < len; ++i){
			tempRanking[suffix[i]] = (ranking[suffix[i]] == ranking[suffix[i-1]] && ranking[suffix[i]+k] == ranking[suffix[i-1]+k]? r : ++r);
		}
		for(i = 0; i < len; ++i)
			ranking[i] = tempRanking[i];
		if(ranking[suffix[len-1]] == len-1) break;
	}

}

void constructlcs(){
	constructSA();
	phi[suffix[0]] = -1;
	int i, longest, ans = 0, index = 0, repetitions = 0;
	string substring = "";
	for(i = 1; i < len; ++i){
		phi[suffix[i]] = suffix[i-1];
	}
	for(i = 0, longest = 0; i < len; ++i){
		if(phi[i] == -1){
			plcp[i] = 0;
			continue;
		}
		while(line[i+longest] == line[phi[i]+longest]){
		       	++longest;
		}
		plcp[i] = longest;
		if(longest && ans <= longest){
			if(ans < longest){
				index = i;
				ans = longest;
				repetitions = 2;
				substring.assign(line+index, line+(index+longest));
			}else{
				string temp(line+i, line+(i+longest));
				if(temp < substring){
					repetitions = 2;
					substring = temp;
				}else if(temp == substring){
					++repetitions;
				}
			}
		}
		longest = max(longest-1, 0);
	}
	if(substring.empty()){
		cout<<"No repetitions found!\n";
	}else{
		cout<<substring<<" "<<repetitions<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin>>t;
	cin.ignore();
	while(t-- && cin.getline(line, MAX_N)){
		len = strlen(line);
		line[len++] = '$';
		constructlcs();
	}
	return 0;
}
