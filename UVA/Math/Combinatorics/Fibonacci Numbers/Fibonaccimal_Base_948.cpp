#include <bits/stdc++.h>

using namespace std;
vector<int> fibo(1);
void numerosFibo(){
	int matrix[2][2]{
			{1,1},
			{1,0}
	};
	int aux[2][2]{
			{1,1},
			{1,0}
	};
	fibo[0]=1;
	for(int x=2; fibo.back()<1e8 ; x++){
		int n1=matrix[0][0];
		int n2=matrix[0][1];
		int n3=matrix[1][0];
		int n4=matrix[1][1];
		matrix[0][0]+=n1*aux[0][0] + n2*aux[1][0];
		matrix[0][1]+=n1*aux[0][1] + n2*aux[1][1];
		matrix[1][0]+=n3*aux[0][0] + n4*aux[1][0];
		matrix[1][1]+=n3*aux[0][1] + n4*aux[1][1];
		fibo.push_back(matrix[0][1]);
		fibo.push_back(matrix[0][0]);
	}
}
int main() {
	int n, num;
	numerosFibo();
	cin>>n;
	while(n--){
		cin>>num;
		string base="";
		bool aux=false;
		int suma=0;
		for(auto iter = fibo.rbegin(); iter!=fibo.rend(); iter++){
			if(!aux&& (suma+*iter)<=num){
				base+="1";
				aux=true;
				suma+=*iter;
			}else if(base.length()>0){
				base+="0";
				aux=false;
			}else{
				aux=false;
			}
		}
		cout<<num<<" = "<<base<<" (fib)\n";
	}
    return 0;
}