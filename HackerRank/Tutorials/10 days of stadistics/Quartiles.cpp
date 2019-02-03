#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,q1,q2,q3,piece;
	cin>>n;
	int values[n];
	for(int x=0; x<n; x++)cin>>values[x];
	sort(values,values+n);
	piece = n/2;
	q1 = piece&1?values[piece/2]: (values[piece/2]+values[(piece/2)-1])/2;
	q2 = (n&1)?values[n/2]: (values[n/2]+values[(n/2)-1])/2;
	q3 = piece&1?values[piece+(piece/2)+(n&1)]: (values[piece+(piece/2)+(n&1)]+values[(piece+(piece/2))-1+(n&1)])/2;
	cout<<q1<<"\n"<<q2<<"\n"<<q3<<"\n";
	return 0;
}