#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, subjects, timeNeeded, limit;
	string subject, homework;
	unordered_map<string,int> times;
	cin>>tests;
	for(int t = 1; t<=tests; t++){
		times.clear();
		cin>>subjects;
		while(subjects--){
			cin>>subject>>timeNeeded;
			times[subject] = timeNeeded;
		}
		cin>>limit;
		cin>>homework;
		timeNeeded = times.find(homework) == times.end() ? 1e9 : times.find(homework)->second;
		cout<<"Case "<<t<<": ";
		if(timeNeeded<=limit){
			cout<<"Yesss\n";
		}else if(timeNeeded<=limit+5){
			cout<<"Late\n";
		}else{
			cout<<"Do your own homework!\n";
		}
	}
	return 0;
}