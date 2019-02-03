#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int students,cal;
	vector<int> finalCal;
	cin>>students;
	while(students--){
		cin>>cal;
		if(cal<38){
			finalCal.push_back(cal);
		}else{
			int dif = abs(cal%5-5);
			if(dif<3){
				finalCal.push_back(cal+dif);
			}else{
				finalCal.push_back(cal);
			}
		}
	}
	for(auto iter = finalCal.begin(); iter!=finalCal.end(); iter++)cout<<*iter<<endl;
	return 0;
}