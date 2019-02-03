#include <bits/stdc++.h>

using namespace std;

double getRank(double *p,double find ,int &size){
	for(int x=0; x<size;x++)
		if(p[x]==find)return x+1;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin>>size;
	double a[size],b[size],sa[size],sb[size];
	for(int x=0; x<size; x++){
		cin>>a[x];
		sa[x] = a[x];
	}
	for(int x=0; x<size; x++){
		cin>>b[x];
		sb[x] = b[x];
	}
	sort(sa,sa+size);
	sort(sb,sb+size);
	double sumRank=0;
	for(int x=0; x<size; x++){
		sumRank+=pow(getRank(sa,a[x],size)-getRank(sb,b[x],size),2);
	}
	double ans = 1-((6*sumRank)/(size*(pow(size,2)-1)));
	cout<<setprecision(3)<<fixed<<ans<<endl;
	return 0;
}
