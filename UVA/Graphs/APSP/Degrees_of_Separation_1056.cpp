#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

void addIfNotPresent(string str, unordered_map<string,int> &table, int &index){
	if(table.find(str) == table.end()){
		table[str] = index++;
	}
}

void createEdge(string a, string b, unordered_map<string,int> &table, vector< vector<int> > &matrix, int value=1){
	matrix[table.find(a)->second][table.find(b)->second] = value;
	matrix[table.find(b)->second][table.find(a)->second] = value;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int names, edges,index,maxDegree, network = 0;
	string name1, name2;
	while(cin>>names>>edges && (names || edges)){
		unordered_map<string,int> table;
		index = maxDegree = 0;
		vector< vector<int> > matrix(names,vector<int>(names,INF));
		while(edges-- && cin>>name1>>name2){
			addIfNotPresent(name1,table,index);
			addIfNotPresent(name2,table,index);
			createEdge(name1,name2,table,matrix);
			createEdge(name1,name1,table,matrix,0);
			createEdge(name2,name2,table,matrix,0);
		}
		for(int k=0; k<matrix.size(); k++){
			for(int i=0; i<matrix.size(); i++){
				for(int j=0; j<matrix.size(); j++){
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
		for(int i=0; i<matrix.size(); i++){
			for(int j=0; j<matrix.size(); j++){
				maxDegree = max(maxDegree, matrix[i][j]);
			}
		}
		cout<<"Network "<<++network<<": ";
		if(maxDegree == INF){
			cout<<"DISCONNECTED\n\n";
		}else{
			cout<<maxDegree<<"\n\n";
		}
	}	
	return 0;
}