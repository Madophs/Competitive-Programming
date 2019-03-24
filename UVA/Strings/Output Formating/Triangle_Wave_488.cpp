#include <bits/stdc++.h>

using namespace std;

string triangle(int amplitude, int i=1){
	string ret= "", temp(i,i+'0');
	if(i<amplitude){
		ret+=temp+"\n";
		ret += triangle(amplitude,i+1);
		ret+="\n";
		ret+=temp;
	}else if(i == amplitude){
		return temp;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, frequency, amplitude;
	cin>>tests;
	for(int t = 0; tests--; t++){
		if(t)cout<<"\n";
		cin>>amplitude>>frequency;
		string output = triangle(amplitude);
		for(int i = 0; i<frequency; i++){
			cout<<output<<"\n";
			if(i+1<frequency) cout<<"\n";
		}
	}
	return 0;
}