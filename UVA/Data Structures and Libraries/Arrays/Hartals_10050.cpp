#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,parties,hartal,days;
	bool calendar[3655];
	cin>>t;
	while(t--){
		memset(calendar,false,sizeof calendar);
		cin>>days>>parties;
		while(parties-- && cin>>hartal)
			for(int x=hartal; x<=days; x+=hartal)calendar[x] = true;
		int noWork = 0;
		for(int x=1; x<=days; x++)
			if(x%7!=0 && (x+1)%7!=0 && calendar[x])++noWork;
		cout<<noWork<<endl;
	}
	return 0;
}
