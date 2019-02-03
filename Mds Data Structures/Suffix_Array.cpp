#include <bits/stdc++.h>
#define MAX_N 100010

using namespace std;

int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int counting[MAX_N];
char word[MAX_N];

void printSuffixArray(int &length){
	for(int i=0; i<length; i++){
		cout<<word+SA[i]<<endl;
	}
}

void countingSort(int k, int &length){
	int i,sum, maxi = max(300,length);
	memset(counting,0,sizeof counting);
	for(i=0; i<length; i++){
		counting[i+k<length?RA[i+k]:0]++;
	}
	for(i=sum=0; i<maxi; i++){
		int temp = counting[i];
		counting[i] = sum;
		sum += temp;
	}
	for(i=0; i<length; i++){
		tempSA[counting[SA[i]+k < length? RA[SA[i]+k]:0]++] = SA[i];
	}
	for(i=0; i<length; i++){
		SA[i] = tempSA[i];
	}
	//printSuffixArray(length);
}

void constructSuffixArray(int &length){
	int i,k,r;
	for(i=0; i<length; i++)RA[i] = word[i],SA[i] = i;
	for(k=1; k<length; k<<=1){
		countingSort(k,length);
		countingSort(0,length);
		tempRA[SA[0]] = r = 0;
		for(i=1; i<length; i++){
			if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]){
				tempRA[SA[i]] = r;
			}else{
				tempRA[SA[i]] = ++r;
			}
		}
		for(i=0; i<length; i++){
			RA[i] = tempRA[i];
		}
		if(RA[SA[length-1]] == length-1)break; 
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin.getline(word,MAX_N);
	int length = strlen(word);
	word[length++] = '$';
	constructSuffixArray(length);
	printSuffixArray(length);
	cout<<word<<" "<<length<<endl;
	return 0;
}