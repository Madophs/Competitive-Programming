#include <bits/stdc++.h>

using namespace std;

int howMany(int &cant, int &s, int &t, int &treePos){
	int posFruit,fruits=0, finalpos=0;
	while(cant--){
		cin>>posFruit;
		finalpos = treePos+posFruit;
		if(finalpos<=t && finalpos>=s)++fruits;
	}
	return fruits;
}

int main(){
	ios_base::sync_with_stdio(false);
	int start, end, num_apples, num_oranges,a ,b;
	cin>>start>>end;
	cin>>a>>b;
	cin>>num_apples>>num_oranges;
	cout<<howMany(num_apples,start,end,a)<<endl;
	cout<<howMany(num_oranges,start,end,b)<<endl;
	return 0;
}