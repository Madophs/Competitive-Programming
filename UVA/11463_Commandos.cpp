#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int>ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef unsigned int ui;

int vertice[100][100];

int floyd_warshall(int tam, int s, int d){
	for(int k=0; k<tam; k++){
		for(int x=0; x<tam; x++){
			for(int y=0; y<tam; y++){
				vertice[x][y]=min(vertice[x][y],vertice[x][k]+vertice[k][y]);
			}
		}
	}
	int res=-1;
	for(int x=0; x<tam; x++){
		res = max(res,vertice[s][x]+vertice[x][d]);
	}
	return res;
}
int main(){
	int tc,caso=0;
	ios_base::sync_with_stdio(false);
	cin>>tc;
	while(tc--){
		int v,e,a,b;
		cin>>v>>e;
		for(int x=0; x<v; x++){
			for(int y=0; y<v; y++){
				vertice[x][y]=inf;
			}
			vertice[x][x]=0;
		}
		while(e--){
			cin>>a>>b;
			vertice[a][b]=1;
			vertice[b][a]=1;
		}
		cin>>a>>b;
		cout<<"Case "<<++caso<<": "<<floyd_warshall(v,a,b)<<endl;
	}
	return 0;
}
