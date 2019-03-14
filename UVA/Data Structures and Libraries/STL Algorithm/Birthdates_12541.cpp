#include <bits/stdc++.h>

using namespace std;

struct Person{
	string name;
	int day, month, year;
	Person(string name, int day, int month, int year){
		this->name = name;
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

bool mdsSort(Person a, Person b){
	if(a.year!=b.year) return a.year > b.year;
	if(a.year == b.year && a.month != b.month) return a.month > b.month;
	return a.day > b.day;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int people, day, month, year;
	string name;
	while(cin>>people){
		vector<Person> persons;
		while(people-- && cin>>name>>day>>month>>year) persons.emplace_back(Person(name,day,month,year));
		sort(persons.begin(), persons.end(), mdsSort);
		cout<<persons[0].name<<"\n"<<persons.back().name<<"\n";
	}
	return 0;
}