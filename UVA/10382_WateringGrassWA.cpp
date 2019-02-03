#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool ordenar(pair<double, double> p1, pair<double, double> p2){
	return p1.first<p2.first;
}
pair<double, double> hacerPar(int p, int r,int w){
	if(pow(r,2)<(double)pow((double)w/2,2)){
		return make_pair(0,0);
	}
	double inter=(double)sqrt(pow(r,2)-(double)pow((double)w/2,2));
	return make_pair((double)((double)p-inter),(double)((double)p+inter));
}
int main(){
	std::ios_base::sync_with_stdio(false);
	string cadena="";
	while(getline(cin,cadena)){
		if(cadena.empty())break;
		int n,l,w,p,r;
		stringstream tk(cadena);
		tk>>n;
		tk>>l;
		tk>>w;
		vector<pair <double, double> > vec;
		while(n--){
			cin>>p>>r;
			vec.push_back(hacerPar(p,r,w));
		}
		sort(vec.begin(),vec.end(),ordenar);
		double j=0;
		int frickles=0;
		for(int x=0; x<vec.size(); x++){
			if(vec[x].first==0 && vec[x].second==0)continue;
			if(vec[x].first>j)break;
			for(int y=x+1; y<vec.size() && vec[y].first<=j; y++){
				if(vec[y].second>vec[x].second){
					x=y;
				}
			}
			++frickles;
			j=vec[x].second;
			if(j>=l)break;
		}

		if(j>=l){
			cout<<frickles<<endl;
		}else{
			cout<<"-1\n";
		}
		cin.ignore();
	}
	return 0;
}
