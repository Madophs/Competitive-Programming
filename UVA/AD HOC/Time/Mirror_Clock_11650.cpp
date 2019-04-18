#include <bits/stdc++.h>

using namespace std;

void getMinutes(string hour, int &h, int &m){
	string token;
	stringstream ss(hour);
	getline(ss,token,':');
	h = atoi(token.c_str());
	getline(ss,token,':');
	m = atoi(token.c_str());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setfill('0')<<right;
	int tests, hour, minute;
	string line;
	cin>>tests;
	while(tests--){
		cin>>line;
		getMinutes(line,hour, minute);
		if(minute != 0) minute = 60 - minute;
		if(hour != 12) hour = 12-hour;
		if(minute != 0)hour = hour == 1 ? 12 : hour - 1;
		cout<<setw(2)<<hour<<":"<<setw(2)<<minute<<"\n";
	}
	return 0;
}