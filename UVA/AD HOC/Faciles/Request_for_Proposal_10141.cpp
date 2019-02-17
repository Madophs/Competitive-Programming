#include <bits/stdc++.h>
#define EPSILON 1e-9
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int req, pro, met,RFP=0;
	double price, lowestPrice = 1.0e9, bestCompliant = -1.0;
	string requirement, proposal, bestProposal;
	bool jump = false;
	while(cin>>req>>pro && (req || pro)){
		if(jump) cout<<'\n';
		jump = true;
		cin.ignore();
		lowestPrice = 1.0e9, bestCompliant = -1.0;
		for(int x = 0; x<req; x++)getline(cin,requirement);
		while(pro--){
			getline(cin, proposal);
			cin>>price>>met;
			double compliant = (double)met/(double)req;
			cin.ignore();
			while(met--) getline(cin, requirement);
			if(bestCompliant < compliant){
				bestProposal = proposal;
				bestCompliant = compliant;
				lowestPrice = price;
			}else if(fabs(bestCompliant - compliant) < EPSILON){
				if(lowestPrice > price){
					bestProposal = proposal;
					lowestPrice = price;
				}
			}
		}
		cout<<"RFP #"<<++RFP<<'\n';
		cout<<bestProposal<<'\n';
	}
	return 0;
}