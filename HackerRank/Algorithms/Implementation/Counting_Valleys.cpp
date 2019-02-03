#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int valleys=0, level=0, antLevel = 0,numSteps;
	string steps;
	cin>>numSteps>>steps;
	for(auto iter = steps.begin(); iter!=steps.end(); iter++){
		antLevel = level;
		level = *iter=='U' ? level+1 : level-1;
		if(iter!=steps.begin())
			if(antLevel<0 && level==0)++valleys;
	}
	cout<<valleys<<endl;
	return 0;
}