#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(3);
	string line, token;
	int hours, minutes;
	int cont = 0;
	while(getline(cin,line) && line!="0:00"){
		stringstream ss(line);
		getline(ss,token,':');
		hours = stoi(token.c_str());
		getline(ss,token,':');
		minutes = atoi(token.c_str());
		double angle = abs(((60.0*hours+minutes)/2.0)-minutes*6.0);
		if(angle > 180) cout<<360-angle<<"\n";
		else cout<<angle<<"\n";
	}
	return 0;
}