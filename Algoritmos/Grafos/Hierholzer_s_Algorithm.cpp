#include <bits/stdc++.h>

using namespace std;

class DirectedGraph{
	public:
	DirectedGraph(int numVer){
		adj.assign(numVer,vector<int>());
		in.assign(numVer,0), out.assign(numVer,0);
		startingNode = 0;
	}
	void insertEdge(int a, int b){
		adj[a].push_back(b);
		//adj[a].push_back(b), adj[b].push_back(a);
	}
	void printEulerianPath(){
		if(!isEulerian()){
			cout<<"No es un grafo de Euler\n";
			return;
		}
		stack<int> currentPath;
		vector<int> tour;
		currentPath.push(startingNode);
		int u = startingNode;
		while(!currentPath.empty()){
			printStack(currentPath);
			if(out[u]>0){
				int v = adj[u].back();
				currentPath.push(v);
				adj[u].pop_back();
				out[u]--;
				/*out[u]--, out[v]--;
				for(auto iter = adj[v].begin(); iter!=adj[v].end(); iter++){
					if(*iter == u){
						adj[v].erase(iter);
						break;
					}
				}*/
				u = v;
			}else{
				tour.push_back(u);
				currentPath.pop();
				if(currentPath.empty()) break;
				u = currentPath.top();
			}
		}
		for(auto i = tour.rbegin(); i!=tour.rend(); i++){
			cout<<*i<<" ";
		}
		cout<<endl;
	}
	void printStack(stack<int> s){
		vector<int> temp;
		while(!s.empty()){
			temp.push_back(s.top());
			s.pop();
		}
		for(auto i = temp.rbegin(); i!=temp.rend(); i++){
			cout<<*i<<(i+1 == temp.rend()?"\n":" ");
		}
	}
	private:
	vector< vector<int> > adj;
	vector<int> in,out;
	int startingNode;

	bool isEulerian(){
		for(int u = 0; u<adj.size(); u++){
			for(int v = 0; v<adj[u].size(); v++){
				++out[u], ++in[adj[u][v]];
			}
		}
		int evens = 0, inLessOut = 0, outLessIn = 0, odds = 0;
		for(int i = 0; i<in.size(); i++){
			/*if(out[i]&1){
				startingNode = i;
				++odds;
				if(odds>2) return false;
			}else{
				++evens;
			}*/
			if(in[i] == out[i]){
				++evens;
			}else{
				if(abs(in[i]-out[i]) > 1) return false;
				if(in[i] - out[i] == i){
					++inLessOut, startingNode = i;
				}else{
					++outLessIn, startingNode = i;
				}
			}
		}
		//return evens == adj.size() || odds == 2;
		return evens == adj.size() || (inLessOut == 1 && outLessIn == 1);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes, edges,a,b;
	cin>>nodes>>edges;
	DirectedGraph dg(nodes);
	while(edges-- && cin>>a>>b) dg.insertEdge(a,b);
	dg.printEulerianPath();
	return 0;
}

/*

7
10
0 1
0 6
1 2
2 0
2 3
3 4
4 2
4 5
5 0
6 4

3
3
0 1
1 2
2 0

5
6
1 3
1 2
2 0
0 1
3 4
4 1

*/