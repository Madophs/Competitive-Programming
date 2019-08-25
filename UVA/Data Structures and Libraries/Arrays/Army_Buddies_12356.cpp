#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int soldiers, reports, l, r;
	while(cin>>soldiers>>reports && (soldiers || reports)){
		vector<int> lineLeft(soldiers+1), lineRight(soldiers+1);
		iota(lineLeft.begin(), lineLeft.end(), -1);
		iota(lineRight.begin(), lineRight.end(), 1);
		while(reports-- && cin>>l>>r){
			if(lineLeft[l] > 0){
				cout<<lineLeft[l]<<" ";
			}else{
				cout<<"* ";
			}
			if(lineRight[r] <= soldiers){
				cout<<lineRight[r]<<"\n";
			}else{
				cout<<"*\n";
			}
			lineLeft[lineRight[r]] = lineLeft[l];
			lineRight[lineLeft[l]] = lineRight[r];
		}
		cout<<"-\n";
	}
	return 0;
}
