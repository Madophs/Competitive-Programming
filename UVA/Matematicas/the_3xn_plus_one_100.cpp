#include <bits/stdc++.h>

using namespace std;
int table[1000001];//Un poco de porogramacion deinamica
//Metodo para contrar el clice length del 3*n+1 problem
int cicleLength(long long int n){
	int c=1,index=n;
	if(table[n]!=0)return table[n];
	while(n!=1){
		if(n & 1){ //Comparamos si es impar la variable n
			n=(3*n)+1;
		}else{
			n>>=1;
		}
		c++;
	}
	table[index]=c;
	return c;
}
int main(){
	long long int i,j; //Si no los declaro asi me da Runtime Error :(
	int result;
	memset(table,0,sizeof(table)/sizeof(int));
	table[1]=1;
	while(cin>>i>>j){
		result=0;
		if(i<j){
			for(int x=i; x<=j; x++){
				result=max(cicleLength(x),result);
			}
		}else if(j<i){
			for(int x=j; x<=i; x++){
				result=max(cicleLength(x),result);
			}
		}else{
			result=max(cicleLength(j),result);//Este no se si sea necesario pero por si acaso
		}
		cout<<i<<" "<<j<<" "<<result<<"\n";
	}
	return 0;
}