#include <bits/stdc++.h>

using namespace std;

bool menorMayor(int a, int b){
	return a>b;
}
bool mayorMenor(int a, int b){
	return a<b;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	int lumberjacks[11];
	cin>>t;
	cout<<"Lumberjacks:\n";
	while(t--){
		memset(lumberjacks,0,sizeof(lumberjacks));
		for(int x=10; x--; )cin>>lumberjacks[x];
		bool sorted = is_sorted(lumberjacks,lumberjacks+10,menorMayor);
		if(sorted){
			cout<<"Ordered\n";
			continue;
		}
		sorted = is_sorted(lumberjacks,lumberjacks+10,mayorMenor);
		cout<<(sorted?"Ordered\n":"Unordered\n");
	}
    return 0;
}
