#include <bits/stdc++.h>

using namespace std;

class Graph {
	private:
		int nodes;
		vector<vector<int>> adj;
		bitset<100005> visited;
	public:
		Graph(int nodes) {
			this->nodes = nodes;
			this->adj.assign(nodes, vector<int>());	
		}
		void insertNode(int from , int to) {
			adj[from].emplace_back(to);
			adj[to].emplace_back(from);
		}
		int visitedNodes(int u) {
			if(visited.test(u)) return 0;
			visited.set(u);
			int visited_nodes = 1;
			for(int &v : adj[u]) {
				if(!visited.test(v)) {
					visited_nodes += visitedNodes(v);
				}
			}
			return visited_nodes;
		}
		long getMinimalCost(int c_library, int c_road) {
			long visited_nodes = 0, ans = 0;
			for(int i = 1; i < (int)adj.size(); ++i) {
				if(!visited.test(i)) {
					visited_nodes = visitedNodes(i);
				long roads_total_cost =  ((visited_nodes-1) * c_road) + c_library;
				long libraries_total_cost = c_library * visited_nodes;
				ans += min(roads_total_cost, libraries_total_cost);
			}
		}
		return ans;
	}	
};				


int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int queries, cities, roads, library_cost, road_cost;
int u, v;
cin >> queries;
while(queries-- && cin >> cities >> roads >> library_cost >> road_cost) {
		Graph city(cities+1);	
		while(roads-- && cin >> u >> v) {
			city.insertNode(u, v);
		}
		cout << city.getMinimalCost(library_cost, road_cost) << "\n";
	}
	return 0;
}
