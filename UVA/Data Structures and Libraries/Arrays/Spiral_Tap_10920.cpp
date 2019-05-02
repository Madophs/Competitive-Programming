#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long spiralSize, position;
	long long line,column;
	while(cin>>spiralSize>>position && (spiralSize || position)){
		long long length = ceil(sqrtl((long double)position)), add = (spiralSize-length)/2LL;
		length += !(length & 1LL);
		long long l1 = length*length, l2 = l1-length, l3 = l2-(length-1LL), l4 = l3-(length-1LL);
		if(position <= l1 && position > l2){
			column = length + add;
			line = position - l2 + add;
		}else if(position <= l2 && position > l3){
			column = position - l3 + add;
			line = 1LL + add;
		}else if(position <= l3 && position > l4){
			column = 1LL + add;
			line = l3 - position + 2LL + add;
		}else{
			line = length + add;
			column = l4 - position + 2LL + add;
		}
		cout<<"Line = "<<line<<", column = "<<column<<".\n";
	}
	return 0;
}
