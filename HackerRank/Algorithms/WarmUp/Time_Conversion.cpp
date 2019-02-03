#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string strTime, token, dayTime;
	cin>>strTime;
	stringstream is(strTime);
	int hrs = 0, min = 0, sec = 0;
	getline(is,token,':');
	hrs = atoi(token.c_str());
	getline(is,token,':');
	min = atoi(token.c_str());
	getline(is,token,':');
	sec = atoi(token.substr(0,2).c_str());
	dayTime = token.substr(2,2);
	if(dayTime=="PM"){
		if(hrs!=12){
			hrs+= 12;
			if(hrs==24)hrs=0;
		}
	}else{
		if(hrs==12)hrs=0;
	}
	cout<<setw(2)<<setfill('0')<<right<<hrs<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<endl;
	return 0;
}