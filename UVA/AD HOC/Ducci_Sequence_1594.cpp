#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int size;
		string tupleString="",zeros="",result="";
		cin>>size;
		unordered_map<string, int> detect;
		int arr[size];
		for(int x=0; x<size; x++){
			if(x>0)zeros+=" ";
			cin>>arr[x];
			tupleString+=to_string(arr[x])+(x+1==size?"":" ");
			zeros+="0";

		}
		detect[tupleString]=0;
		string aux="";
		while(true){
			aux="";
			vector<int> vec(arr,arr+size);
			for(int x=0; x<size; x++){
				if(x+1==size){
					arr[x]=abs(vec[x]-vec[0]);
					aux+=to_string(arr[x]);
				}else{
					arr[x]=abs(vec[x]-vec[x+1]);
					aux+=to_string(arr[x])+" ";
				}
			}
			if(zeros==aux){
				result="ZERO\n";
				break;
			}
			if(detect.find(aux)!=detect.end()){
				result="LOOP\n";
				break;
			}
			detect[aux]=0;
		}
		cout<<result;
	}
    return 0;
}