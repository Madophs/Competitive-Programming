#include <bits/stdc++.h>

using namespace std;

double normalDistribution(double mean, double sd,double x){
    return 0.5*(1.0+erf((x-mean)/(sd*sqrt(2.0))));
}

int main(){
    ios_base::sync_with_stdio(false);
    double mean,sd,a,b;
    cin>>mean>>sd>>a>>b;
    cout<<setprecision(3)<<fixed<<(1.0-normalDistribution(mean,sd,a))*100.0<<endl;
    cout<<setprecision(3)<<fixed<<(1.0-normalDistribution(mean,sd,b))*100.0<<endl;
    cout<<setprecision(3)<<fixed<<(normalDistribution(mean,sd,b))*100.0<<endl;
    return 0;
}
