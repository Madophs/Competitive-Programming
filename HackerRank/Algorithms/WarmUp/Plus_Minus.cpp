#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int count,p,n,z,trash,aux;
	p=n=z=trash=0;
	cin>>count;
	aux=count;
	while(aux--){
		cin>>trash;
		if(trash>0){
			++p;
		}else if(trash<0){
			++n;
		}else{
			++z;
		}
	}
	double radioPos = (double)p/(double)count,radioNeg = (double)n/(double)count, radioZero = (double)z/(double)count;
	cout<<setprecision(6)<<fixed<<radioPos<<"\n"<<radioNeg<<"\n"<<radioZero<<endl;
	return 0;
}