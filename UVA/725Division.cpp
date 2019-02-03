#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n=0,cont=0;;
	while(cin>>n && n){
		if(cont>0)cout<<endl;
		++cont;
		bool no=true;
		for(int fghij=1234; fghij<=98765/n; fghij++){
			int abcde=n*fghij;
			int temp,used=(fghij<10000);
			temp=abcde;
			while(temp){
				used|=(1<<temp%10);
				temp/=10;
			}
			temp=fghij;
			while(temp){
				used|=(1<<temp%10);
				temp/=10;
			}
			if(used==(1<<10)-1){
				no=false;
				cout<<abcde<<" / "<<fixed<<setfill('0')<<setw(5)<<fghij<<" = "<<n<<endl;
			}
		}
		if(no){
			cout<<"There are no solutions for "<<n<<"."<<endl;
		}
	}
	return 0;
}
