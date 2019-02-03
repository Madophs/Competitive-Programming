#include <iostream>
using namespace std;

int main(){
	int k=0;
	bool turno =false;
	while(cin>>k && k){
		if(turno)cout<<endl;
		turno=true;
		int arr[k];
		for(int x=0; x<k; x++){
			cin>>arr[x];
		}
		for(int a=0; a<k; a++){
			for(int b=a+1; b<k; b++){
				for(int c=b+1; c<k; c++){
					for(int d=c+1; d<k; d++){
						for(int e=d+1; e<k; e++){
							for(int f=e+1; f<k; f++){
								cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<" "<<arr[d]<<" "<<arr[e]<<" "<<arr[f]<<endl;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
