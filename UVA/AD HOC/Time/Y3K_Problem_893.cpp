#include <bits/stdc++.h>

using namespace std;


int monthDays[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date{
	public:
		Date(int day, int month, int year){
			this->day = day;
			this->month = month;
			this->year = year;
		}
		int getDay() const{
			return this->day;
		}
		int getMonth() const{
			return this->month;
		}
		int getYear() const{
			return this->year;
		}
		bool isLeapYear(int y){
			return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
		}
		int getDaysPassedByMonth(){
			int days = day;
			for(int i = 0; i<month; i++){
				days += monthDays[i];
			}
			if(month > 2 && isLeapYear(year)) ++days;
			return days;
		}
		int getNumberOfLeapYears(int y){
			return (y/4) - (y/100) + (y/400);
		}

		int calculateDaysPassed(){
			int daysPassed = getDaysPassedByMonth();
			int leapYears = getNumberOfLeapYears(year-1);
			return ((year-1)*365) + leapYears + daysPassed; 
		}
		void addDays(int forwardDays){
			int countDays = calculateDaysPassed() + forwardDays;
			int newDay = 0, newMonth = 1, newYear = 1;
			int numDays = 365;
			while(countDays > numDays){
				countDays -= numDays;
				++newYear;
				numDays = isLeapYear(newYear) ? 366 : 365;
			}
			if(isLeapYear(newYear)) monthDays[2] = 29;
			for(int i = 1; countDays > monthDays[i]; i++, ++newMonth){
				countDays -= monthDays[i];
			}
			monthDays[2] = 28;
			this->year = newYear;
			this->day = countDays;
			this->month = newMonth;
		}
	private:
		int day, month, year;
};

ostream & operator << (ostream &out, const Date &date){
	out<<date.getDay()<<" "<<date.getMonth()<<" "<<date.getYear();
	return out;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int daysToPredict, day, month, year;
	while(cin>>daysToPredict>>day>>month>>year && (daysToPredict || day || month || year)){
		Date date(day, month, year);
		date.addDays(daysToPredict);
		cout<<date<<"\n";
		
	}
	return 0;
}