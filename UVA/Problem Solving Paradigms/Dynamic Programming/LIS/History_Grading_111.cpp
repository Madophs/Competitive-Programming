#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numEvents, val;
	string line;
	cin>>numEvents;
	do{
		vector<int> ids(numEvents);
		numEvents = 0;
		for(int i = 0; i<ids.size() && cin>>val; i++) ids[i] = val;
		cin.ignore();
		bool printSolution = true;
		while(printSolution && getline(cin,line)){
			stringstream ss(line);
			vector<int> exam(ids.size());
			int countTokens = 0;
			while(ss>>val){
				++countTokens;
				if(ss.eof() && countTokens == 1){
					numEvents = val;
					printSolution = false;
					break;
				}else{
					exam[val-1] = ids[countTokens-1];
				}
			}
			if(printSolution){
				int lis_init = 0, lis_array[ids.size()];
				for(int i = 0; i<ids.size(); i++){
					int pos = lower_bound(lis_array, lis_array+lis_init,exam[i]) - lis_array;
					lis_array[pos] = exam[i];
					if(pos + 1 > lis_init){
						lis_init = pos + 1;
					}
				}
				cout<<lis_init<<"\n";
			}
		}
	}while(numEvents);
	return 0;
}