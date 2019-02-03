#include <bits/stdc++.h>
#define EPSILON 1e-9
using namespace std;

double puntiation(char c){
	if(c=='q' || c == 'w' || c=='e' || c=='r' || c=='t')return 0.2;
	return 0.1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,words;
	string w;
	double sum,score;
	unordered_map<string,double> table;
	cin>>t;
	while(t--){
		cin>>words;
		sum = 0.0;
		table.clear();
		while(words-- && cin>>w){
			sum+=0.3;
			if(table.find(w) == table.end()){
				table[w] = 0.0;
			}else{
				sum+=(table.find(w)->second/2.0);
				continue;
			}
			auto iter = table.find(w);
			bool left = false, right = false;
			double multi = 1.0;
			for(int x=0; x<w.length(); x++){
				double f = puntiation(w[x]);
				if(f==0.1){
					left = false;
					if(right){
						multi*=2.0;
						sum+=f*multi;
						iter->second+=f*multi;
					}else{
						right = true;
						multi = 1.0;
						sum+=f;
						iter->second+=f;
					}
				}else{
					right = false;
					if(left){
						multi*=2.0;
						sum+=f*multi;
						iter->second+=f*multi;
					}else{
						left = true;
						multi = 1.0;
						sum+=f;
						iter->second+=f;
					}
				}
			}
		}
		cin>>score;
		sum-=0.3;
		cout<<setprecision(2)<<fixed;
		if( fabs(score - sum) < EPSILON){
			cout<<"GOOD, "<<sum<<"\n";
		}else if(sum > score){
			cout<<"GREAT JOB, "<<sum<<"\n";
		}else{
			cout<<"WORK HARDER, "<<sum<<"\n";
		}
	}
	return 0;
}