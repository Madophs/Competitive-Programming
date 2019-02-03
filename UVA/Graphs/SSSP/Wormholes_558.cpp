#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,stars,wormholes,a,b,cost;
	cin>>t;
	while(t-- && cin>>stars>>wormholes){
		vector<vector<pair<int,int >>> nodes(stars, vector<pair<int,int>>());
		vector<int> distance(stars,inf);
		while(wormholes-- && cin>>a>>b>>cost){
			nodes[a].push_back(make_pair(cost,b));
		}
		distance[0] = 0;
		for(int x=0; x<nodes.size()-1; x++){
			for(int u = 0; u<nodes.size(); u++){
				for(int v = 0; v<nodes[u].size(); v++){
					distance[nodes[u][v].second] = min(distance[nodes[u][v].second], distance[u] + nodes[u][v].first);
				}
			}
		}
		bool possible = false;
		for(int u = 0; u<nodes.size() && !possible; u++){
			for(int v = 0; v<nodes[u].size() && !possible; v++){
				if(distance[nodes[u][v].second] > distance[u]+nodes[u][v].first){
					possible = true;
				}
			}
		}
		cout<<(possible?"possible\n":"not possible\n");
	}
	return 0;
}