#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	float high,distance,slide,fatigue;
	while(cin>>high>>distance>>slide>>fatigue){
		if(high==0.0)break;
		fatigue=(fatigue*distance)/100;
		int day=0;
		float climbed=0.0;
		bool success=true;
		while(true){
			++day;
			climbed+=distance;
			if(distance>0.0)distance-=fatigue;
			if(climbed>high){
				break;
			}
			climbed-=slide;
			if(climbed<0.0){
				success=false;
				break;
			}
		}
		if(success){
			cout<<"success on day "<<day<<"\n";
		}else{
			cout<<"failure on day "<<day<<"\n";
		}
	}
    return 0;
}