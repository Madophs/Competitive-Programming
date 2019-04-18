#include <bits/stdc++.h>

using namespace std;

struct Date{
	int year, month, day;
	Date(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year;
	}

	bool operator < (Date date) const{
		if(this->year < date.year) return true;
		if(this->year == date.year && this->month < date.month) return true;
		return this->year == date.year && this->month == date.month && this->day < date.day;
	}
};

Date castToDate(string d){
	int day, month, year;
	string token;
	stringstream ss(d);
	getline(ss,token,'/');
	day = atoi(token.c_str());
	getline(ss,token,'/');
	month = atoi(token.c_str());
	getline(ss,token,'/');
	year = atoi(token.c_str());
	return Date(day,month, year);
}

int getYearsOld(string d1, string d2){
	if(d1 == d2) return -1;
	Date current = castToDate(d1);
	Date birth = castToDate(d2);
	if(current < birth) return -2;
	int years_old = current.year - birth.year;
	if(current.month < birth.month || (current.month == birth.month && current.day < birth.day))
		--years_old;
	return years_old;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string date1, date2;
	int tests;
	cin>>tests;
	for(int t = 1; tests-- && cin>>date1>>date2; t++){
		int years_old = getYearsOld(date1, date2);
		cout<<"Case #"<<t<<": ";
		if(years_old == -1){
			cout<<"0\n";
		}else if(years_old == -2){
			cout<<"Invalid birth date\n";
		}else if(years_old > 130){
			cout<<"Check birth date\n";
		}else{
			cout<<years_old<<"\n";
		}
	}
	return 0;
}