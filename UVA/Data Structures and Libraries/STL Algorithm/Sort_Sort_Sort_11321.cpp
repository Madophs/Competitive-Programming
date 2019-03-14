#include <bits/stdc++.h>

using namespace std;

int num, modulo,val;

bool mdsSort(int a, int b){
	int modA = a%modulo, modB = b%modulo;
	if(modA == modB){
		if(a&1 && b&1){
			return a>b;
		}else if(a%2 == 0 && b%2 == 0){
			return a<b;
		}else{
			return a&1;
		}
	}
	return modA<modB;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>num>>modulo && (num || modulo)){
		vector<int> numbers;
		while(num-- && cin>>val) numbers.emplace_back(val);
		sort(numbers.begin(), numbers.end(), mdsSort);
		cout<<numbers.size()<<" "<<modulo<<"\n";
		for(auto i = numbers.begin(); i!=numbers.end(); i++){
			cout<<*i<<"\n";
		}
	}
	cout<<num<<" "<<modulo<<"\n";
	return 0;
}