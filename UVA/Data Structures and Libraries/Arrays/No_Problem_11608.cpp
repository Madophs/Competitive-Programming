#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cont=0,initialProblems, currentProblems,required;
	int problems[12];
	while(cin>>initialProblems && initialProblems>=0){
		currentProblems = initialProblems;
		for(int x=0; x<12 && cin>>problems[x]; x++);
		cout<<"Case "<<++cont<<":\n";
		for(int x=0; x<12; x++){
			cin>>required;
			if(required <= currentProblems){
				cout<<"No problem! :D\n";
				currentProblems-=required;
			}else{
				cout<<"No problem. :(\n";
			}
			currentProblems+=problems[x];
		}
	}	
	return 0;
}