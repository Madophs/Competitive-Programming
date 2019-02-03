#include <bits/stdc++.h>

using namespace std;
int matrix[11];

int catalan(int num){
	if(matrix[num]!=0)return matrix[num];
	matrix[0]=matrix[1]=1;
	for(int x=2; x<=num; x++){
		matrix[x]=0;
		for(int y=0; y<x; y++){
			matrix[x]+=matrix[y]*matrix[x-y-1];
		}
	}
	return matrix[num];
}
int main(){
	memset(matrix,0,sizeof(matrix)/sizeof(int));
	int pairs;
	catalan(10);
	int c=0;
	while(cin>>pairs){
		if(c)cout<<"\n";
		c=1;
		cout<<matrix[pairs]<<"\n";
	}
	return 0;
}