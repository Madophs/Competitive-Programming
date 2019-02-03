#ifdef JUDGE
	#include <fstream>
	using namespace std;
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
	#include <iostream>
	using namespace std;
#endif
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a,b;
	cin>>a>>b;
	b*=b;
	cout<<a+b<<'\n';	
	return 0;
}