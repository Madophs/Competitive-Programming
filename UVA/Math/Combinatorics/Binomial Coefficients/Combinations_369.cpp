#include <bits/stdc++.h>

using namespace std;

long long binomials[102][102];

void computeBinomials(){
	int i,j;
	for(i = 0; i<101; i++){
		for(j = 0; j<=i; j++){
			if(j == i || j == 0){
				binomials[i][j] = 1;
			}else{
				binomials[i][j] = binomials[i-1][j] + binomials[i-1][j-1];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	computeBinomials();
	int n, m;
	while(cin>>n>>m && (n || m)){
		cout<<n<<" things taken "<<m<<" at a time is "<<binomials[n][m]<<" exactly.\n";
	}
	return 0;
}