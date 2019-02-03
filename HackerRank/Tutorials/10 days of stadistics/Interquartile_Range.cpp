#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, frec, piece;
	double q1,q2,q3;
	cin>>n;
	int list[n];
	vector<double> values;
	for(int x=0; x<n; x++)cin>>list[x];
	for(int x=0; x<n; x++){
		cin>>frec;
		while(frec--)values.push_back((double)list[x]);
	}
	sort(values.begin(), values.end());
	n = values.size();
	piece = n/2;
	q1 = piece&1?values[piece/2]: (double)(values[piece/2]+values[(piece/2)-1])/2.0;
	q2 = (n&1)?values[n/2]: (double)(values[n/2]+values[(n/2)-1])/2.0;
	q3 = piece&1?values[piece+(piece/2)+(n&1)]: (double)(values[piece+(piece/2)+(n&1)]+values[(piece+(piece/2))-1+(n&1)])/2.0;
	cout<<setprecision(1)<<fixed<<(double)(q3-q1)<<endl;
	return 0;
}