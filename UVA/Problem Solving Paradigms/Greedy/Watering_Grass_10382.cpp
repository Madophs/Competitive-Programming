#include <bits/stdc++.h>

using namespace std;

pair<double,double> computeCovering(double radius, double width, double position){
	double a = radius*radius, b = pow(width/2.0,2);
	double covering = sqrt(a-b);
	return make_pair(position-covering, position+covering);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sprinkles, length, width, position, radius;
	while(cin>>sprinkles>>length>>width){
		vector<pair<double,double>> vec;
		while(sprinkles-- && cin>>position>>radius){
			pair<double,double> p = computeCovering((double)radius,(double)width,(double)position);
			if(!isnanf(p.first)) vec.emplace_back(p);
		}
		sort(vec.begin(), vec.end());
		int ans = 0;
		double i = 0.0, j = 0.0, x = 0;
		while(j<length){
			int aux = x;
			for(; x<vec.size(); x++){
				if(vec[x].first > i) break;
				if(vec[x].second>=j){
					j = vec[x].second;
				}
			}
			if(aux == x)break;
			++ans;
			i = j;
		}
		if(j<(double)length){
			cout<<"-1\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}