#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(3);
	int tests, students;
	cin>>tests;
	while(tests-- && cin>>students){
		vector<double> grades(students);
		double average = 0.0, sum = 0.0, porcentage = 0.0;
		int aboveAverage = 0;
		for(int i = 0; i<grades.size() && cin>>grades[i]; i++) sum += grades[i];
		average = sum/(double)students;
		for(int i = 0; i<grades.size(); i++) if(grades[i] > average) ++aboveAverage;
		porcentage = (aboveAverage*100.0)/students;
		cout<<porcentage<<"%\n";
	}
	return 0;
}
