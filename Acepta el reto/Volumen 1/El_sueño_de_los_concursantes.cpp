#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int noches;
	string tiempo;
	while(cin>>noches && noches){
		int totalMinutos = 0;
		while(noches--){
			cin>>tiempo;
			int dormirHora = atoi(tiempo.substr(0,2).c_str());
			if(dormirHora == 0) dormirHora = 24;
			int dormirMinuto = atoi(tiempo.substr(3,2).c_str());
			int despertarHora = atoi(tiempo.substr(6,2).c_str());
			int despertarMinuto = atoi(tiempo.substr(9,2).c_str());
			if(dormirHora <= 10){
				totalMinutos += ((despertarHora - dormirHora)*60) - dormirMinuto + despertarMinuto;
			}else{
				if(despertarHora > 10){
					totalMinutos += ((despertarHora - dormirHora)*60) - dormirMinuto + despertarMinuto;
				}else{
					totalMinutos += (((24-dormirHora)*60)-dormirMinuto) + (despertarHora*60) + despertarMinuto;
				}
			}
		}
		cout<<fixed<<setfill('0')<<setw(2)<<right<<totalMinutos/60<<":"<<setw(2)<<right<<totalMinutos%60<<"\n";
	}
	return 0;
}
