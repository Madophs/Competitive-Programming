#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> numbers;
	unordered_map<int,int> tableNumbers;
	int num;
	while(cin>>num){
		if(tableNumbers.find(num) == tableNumbers.end()){
			tableNumbers[num] = 1;
			numbers.push_back(num);
		}else{
			tableNumbers.find(num)->second++;
		}
	}
	for(auto n = numbers.begin(); n!=numbers.end(); n++){
		cout<<*n<<" "<<tableNumbers.find(*n)->second<<'\n';
	}
	return 0;
}