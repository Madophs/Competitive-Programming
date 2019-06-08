#include <bits/stdc++.h>

using namespace std;

pair<string,int> toBinaryAndOnes(int number){
	string binaryNumber = "";
	int positiveBits = 0;
	for(int i = 0; number; i++){
		if(number & 1){
			++positiveBits;
			binaryNumber = "1" + binaryNumber;
		}else{
			binaryNumber = "0" + binaryNumber;
		}
		number>>=1;
	}
	return make_pair(binaryNumber, positiveBits);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number;
	while(cin>>number && number){
		pair<string,int> ans = toBinaryAndOnes(number);
		cout<<"The parity of "<<ans.first<<" is "<<ans.second<<" (mod 2).\n";
	}
	return 0;
}
