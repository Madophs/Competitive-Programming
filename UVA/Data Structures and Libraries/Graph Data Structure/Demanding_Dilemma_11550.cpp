#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, nodes, edges, val;
	bool matrix[9][9];
	vector<pair<int,int>> vec;
	cin>>tests;
	while(tests--){
		cin>>nodes>>edges;
		vec.assign(edges, make_pair(-1,-1));
		memset(matrix, false, sizeof matrix);
		bool undirected_graph = true;
		for(int i = 0; i<nodes; i++){
			for(int j = 0; j<edges && cin>>val; j++){
				if(val){
					if(vec[j].first == -1 || vec[j].second == -1){
						if(vec[j].first == -1){
							vec[j].first = i;
						}else{
							vec[j].second = i;
						}
					}else{
						undirected_graph = false;
					}
				}
			}
		}
		if(undirected_graph){
			for(int i = 0; i<vec.size() && undirected_graph; i++){
				if(vec[i].first != -1 && vec[i].second != -1){
					int row = vec[i].first, col = vec[i].second;
					if(!matrix[row][col]) matrix[row][col] = true;
					else undirected_graph = false;
					if(!matrix[col][row]) matrix[col][row] = true;
					else undirected_graph = false;
				}else{
					undirected_graph = false;
				}
			}
			cout<<(undirected_graph?"Yes\n":"No\n");
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}