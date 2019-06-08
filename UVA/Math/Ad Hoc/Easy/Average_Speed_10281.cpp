#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line,aux,strTime;
	double speed = 0.0,prevSpeed, currentDistance = 0.0, currentTime = 0.0, prevTime = 0.0;
	vector<double> units(3,0.0);
	while(getline(cin,line) && !line.empty()){
		stringstream ss(line);
		ss>>strTime;
		stringstream input(strTime);
		for(int i = 0; getline(input,aux,':'); i++) units[i] = atof(aux.c_str());
		currentTime = ((units[0]*60*60)+units[1]*60+units[2])/60.0;
		if(!ss.eof() && ss>>speed){
			currentDistance += ((currentTime-prevTime)*prevSpeed)/60;
		}else{
			currentDistance += ((currentTime-prevTime)*prevSpeed)/60;
			cout<<strTime<<" "<<fixed<<setprecision(2)<<currentDistance<<" km"<<endl;
		}
		prevTime = currentTime;
		prevSpeed = speed;
	} 
	return 0;
}