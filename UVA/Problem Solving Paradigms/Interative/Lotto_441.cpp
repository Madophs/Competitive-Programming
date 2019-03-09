#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,value;
	int arr[6];
	bool jump = false;
	while(cin>>size && size){
		vector<int> numbers;
		for(int i = 0; i<size && cin>>value; i++) numbers.push_back(value);
		if(jump) cout<<"\n";
		jump = true;
		for(arr[0] = 0; arr[0]<numbers.size() ; arr[0]++){
			for(arr[1] = arr[0]+1; arr[1]<numbers.size() ; arr[1]++){
				for(arr[2] = arr[1]+1; arr[2]<numbers.size() ; arr[2]++){
					for(arr[3] = arr[2]+1; arr[3]<numbers.size(); arr[3]++){
						for(arr[4] = arr[3]+1; arr[4]<numbers.size(); arr[4]++){
							for(arr[5] = arr[4]+1; arr[5]<numbers.size(); arr[5]++){
								for(int i = 0; i<6; i++){
									if(i)cout<<" ";
									cout<<numbers[arr[i]];
								}
								cout<<'\n';
							}
						}
					}
				}
			}
		}
	}
	return 0;
}