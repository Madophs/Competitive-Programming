#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int months,depreciations;
	double downPayment,loan;
	cout<<fixed<<setprecision(10);
	while(cin>>months>>downPayment>>loan>>depreciations){
		if(months<0)break;
		int month=0,prevMonth=-1,ans=-1;
		double depreciation=0,antDepre=-1,debt=loan,car=loan+downPayment;
		downPayment=loan/months;
		for(int x=depreciations;x--;){
			cin>>month>>depreciation;
			if(prevMonth==-1){
				prevMonth=month;
				antDepre=depreciation;
			}else{
				for(int x=prevMonth; x<month; x++){
					car-=(car*antDepre);
					if((debt-(downPayment*x))<car && ans==-1){
						ans=x;
					}
				}
				prevMonth=month;
				antDepre=depreciation;
			}
		}
		if(ans==-1){
			for(int x=prevMonth; x<months; x++){
				car-=car*antDepre;
				if((debt-(downPayment*x))<car && ans==-1){
					ans=x;
					break;
				}
			}
		}
		if(ans==1){
			cout<<ans<<" month\n";
		}else{
			ans=(ans==-1)?months:ans;
			cout<<ans<<" months\n";
		}

	}
    return 0;
}