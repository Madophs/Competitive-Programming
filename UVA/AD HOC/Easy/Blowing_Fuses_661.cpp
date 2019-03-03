#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sequence=0, devices, operations, fuseCapacity;
	int op,sum,maximum;
	bool blown;
	while(cin>>devices>>operations>>fuseCapacity && (devices || operations || fuseCapacity)){
		vector<int> ampers(devices+1,0);
		vector<bool> turned(devices+1,false);
		maximum = blown = sum = 0;
		for(int dev = 1; dev<=devices && cin>>ampers[dev]; dev++);
		while(operations-- && cin>>op){
			if(turned[op]){
				sum-=ampers[op];
				turned[op] = false;
			}else{
				sum+=ampers[op];
				turned[op] = true;
			}
			maximum = max(sum,maximum);
			if(sum>fuseCapacity){
				blown = true;
			}
		}
		cout<<"Sequence "<<++sequence<<'\n';
		if(blown){
			cout<<"Fuse was blown.\n";
		}else{
			cout<<"Fuse was not blown.\n";
			cout<<"Maximal power consumption was "<<maximum<<" amperes.\n";
		}
		cout<<'\n';
	}
	return 0;
}