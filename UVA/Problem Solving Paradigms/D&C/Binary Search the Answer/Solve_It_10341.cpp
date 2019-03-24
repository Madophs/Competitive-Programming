#include <bits/stdc++.h>
#define EPSILON 1e-9

using namespace std;

double p,q,r,s,t,u;

double solveEquation(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x*x)+u;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int limit = log10((10000.0-0.0001)/EPSILON)/log10(2);
	cout<<fixed<<setprecision(4);
	while(cin>>p>>q>>r>>s>>t>>u){
		double lower = 0, upper = 1, middle = 0.0, ret = 0.0;
		for(int i = 0; i<limit; i++){
			middle = (lower+upper)/2.0;
			ret = solveEquation(middle);
			if(ret > EPSILON){
				lower = middle;
			}else{
				upper = middle;
			}
		}
		if(ret>-1e-4 && ret<1e-4){
			cout<<middle<<"\n";
		}else{cout<<"No solution\n";
		}
	}
	return 0;
}