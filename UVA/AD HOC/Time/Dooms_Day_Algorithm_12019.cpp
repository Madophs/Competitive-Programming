#include<bits/stdc++.h>
using namespace std;
string getDay(int day, int month, int year){
	int months[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
	string days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	if((year%4==0 && year%100) || (year%400==0))months[2]=60;
	int leap = (floor((year-1)/4)+floor((year-1)/400)-floor((year-1)/100));
	int ordinary=year-1-leap;
	int odd_day=(leap*2+ordinary+months[month-1]+day)%7;
	return days[odd_day];
}
int main(){
	ios::sync_with_stdio(false);
	int t,month,day;cin>>t;
	while(t--){
		cin>>month>>day;
		cout<<getDay(day,month,2011)<<"\n";
	}
	return 0;
}
