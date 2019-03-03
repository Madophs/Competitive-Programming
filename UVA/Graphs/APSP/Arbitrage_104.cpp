#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	while(cin>>size){
		vector< vector<double> > values(size, vector<double>(size,0.0));
		vector< vector<double> > parent(size, vector<double>(size,0.0));
		for(int x=0; x<values.size(); x++){
			for(int y=0; y<values.size(); y++){
				parent[x][y] = x;
				if(x==y) continue;
				cin>>values[x][y];
				//values[x][y]*=-1.0;
			}
		}
		for(int k=0; k<values.size(); k++){
			for(int i=0; i<values.size(); i++){
				for(int j=0; j<values.size(); j++){
					if(values[i][j] > values[i][k]+values[k][j]){
						//values[i][j] = values[i][k] + values[k][j];
						parent[i][j] = parent[k][j];
					}
					values[i][j] = fmin(values[i][j], values[i][k] * values[k][j]);
				}
			}
		}
		for(int i=0; i<values.size(); i++){
			for(int j=0; j<values.size(); j++){
				cout<<values[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}