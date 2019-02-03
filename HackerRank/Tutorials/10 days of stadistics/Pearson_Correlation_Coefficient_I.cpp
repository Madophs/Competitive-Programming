#include <bits/stdc++.h>

using namespace std;

double getMean(double *a,int &size){
	double sum=0;
	for(int x=0; x<size; x++)sum+=a[x];
	return sum/size;
}
double standardDeviation(double *a, int &size){
	double mean = getMean(a,size),dif=0;
	for(int x=0; x<size; x++){
		dif+=pow(mean-a[x],2);
	}
	return sqrt(dif/(double)(size));
}
double getCoverance(double *a, double *b,double &m1,double &m2,int &size){
	double res=0;
	for(int x=0; x<size; x++)res += (a[x]-m1)*(b[x]-m2);
	return res/static_cast<double>(size);
}

double pearsonCorrelationCoefficient(double *a, double *b,int &size){
	double mean1 = getMean(a,size),mean2 = getMean(b,size);
	double sd1 = standardDeviation(a,size), sd2 = standardDeviation(b,size);
	return getCoverance(a,b,mean1,mean2,size)/(sd1*sd2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin>>size;
	double *a = new double[size], *b = new double[size];
	for(int x=0; x<size; x++)cin>>a[x];
	for(int x=0; x<size; x++)cin>>b[x];
	cout<<setprecision(3)<<fixed<<pearsonCorrelationCoefficient(a,b,size)<<endl;
	return 0;
}