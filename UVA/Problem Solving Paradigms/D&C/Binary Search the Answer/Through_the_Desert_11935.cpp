#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	int prevDistance = 0, currentDistance = 0, leaks = 0, consumption = 0;
	double gasoline = 0.0, gasolineNeeded = 0.0;
	string token;
	cout<<fixed<<setprecision(3);
	while(getline(cin,line) && line!="0 Fuel consumption 0"){
		stringstream ss(line);
		ss>>currentDistance;
		ss>>token;
		double diff = (double)(currentDistance-prevDistance);
		gasoline += ((diff/100.0)*consumption)+(leaks*diff);
		if(token == "Fuel"){
			ss>>token;
			ss>>consumption;
		}else if(token == "Leak"){
			++leaks;
		}else if(token == "Gas"){
			ss>>token;
			gasolineNeeded = fmax(gasolineNeeded, gasoline);
			gasoline = 0;
		}else if(token == "Mechanic"){
			leaks = 0;
		}else{
			cout<<fmax(gasolineNeeded,gasoline)<<endl;
			prevDistance = 0, currentDistance = 0, leaks = 0, consumption = 0;
			gasoline = 0.0, gasolineNeeded = 0.0;
		}
		prevDistance = currentDistance;
	}
	return 0;
}