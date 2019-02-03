#include <bits/stdc++.h>
#define unvisited -1

using namespace std;

struct Server{
	vector<Server*> adj;
	int name;
	Server(int name):name(name){} 
};

class Network{
public:
	vector< pair<int,int> > links;
	Network(int size){
		for(int x = 0; x<size; x++) servers.push_back(new Server(x));
		parent.assign(size,0);
		dfs_low.assign(size,-1);
		dfs_num.assign(size,-1);
		counter = 0,rootChildren = 0;
	}
	void insertServer(int name,int connections){
		int serverConnection;
		while(connections-- && cin>>serverConnection){
			servers[name]->adj.push_back(servers[serverConnection]);
		}
	}
	void criticalLinks(){
		for(int x = 0; x<servers.size(); x++){
			if(dfs_num[servers[x]->name] == unvisited){
				criticalLinks(servers[x]->name);
			}
		}
		sort(links.begin(), links.end());
	}
	void criticalLinks(int server){
		dfs_low[server] = dfs_num[server] = counter++;
		for(auto it = servers[server]->adj.begin(); it!=servers[server]->adj.end(); it++){
			auto ref = *it;
			if(dfs_num[ref->name] == unvisited){
				parent[ref->name] = server;
				criticalLinks(ref->name);
				if(dfs_low[ref->name] > dfs_num[server]){
					links.push_back( make_pair(min(server,ref->name),max(server,ref->name)));
				}
				dfs_low[server] = min(dfs_low[server],dfs_low[ref->name]);
			}else if(ref->name != parent[server]){
				dfs_low[server] = min(dfs_low[server], dfs_num[ref->name]);
			}
		}
	}
private:
	vector<Server*> servers;
	vector<int> dfs_num, dfs_low, parent;
	int counter,rootChildren;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,numServer,numConnections;
	string str;
	while(cin>>size){
		Network network(size);
		while(size--){
			cin>>numServer>>str;
			numConnections = atoi(str.substr(1,str.length()-2).c_str());
			network.insertServer(numServer,numConnections);
		}
		network.criticalLinks();
		cout<<network.links.size()<<" critical links\n";
		for(int x = 0; x<network.links.size(); x++){
			cout<<network.links[x].first<<" - "<<network.links[x].second<<"\n";
		}
		cout<<'\n';
	}
	return 0;
}