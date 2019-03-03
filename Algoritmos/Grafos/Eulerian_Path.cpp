#include <bits/stdc++.h>

using namespace std;

class EulerianGraph{
	public:
		EulerianGraph(int nodes){
			vector< pair<int,bool> > temp;
			for(int x=0; x<nodes; x++){
				table[x] = temp;
			}
		}
		void connectNodes(int a, int b){
			auto it1 = table.find(a);
			auto it2 = table.find(b);
			it1->second.push_back(make_pair(b,true));
			it2->second.push_back(make_pair(a,true));
		}
		void EulerTour(list<int>::iterator it, int u){
			auto uNode = table.find(u);
			for(auto v = uNode->second.begin(); v!=uNode->second.end(); v++){
				if(v->second){
					v->second = false;
					auto vNode = table.find(v->first);
					for(auto w = vNode->second.begin(); w!=vNode->second.end(); w++){
						if(w->first == u && w->second){
							w->second = false;
							break;
						}
					}
					EulerTour(path.insert(it,u), v->first);
				}
			}
		}
		void printEulerianPath(){
			path.clear();
			EulerTour(path.begin(),3);
			for(auto it = path.begin(); it!=path.end(); it++){
				cout<<*it<<" ";
			}
			cout<<endl;
		}
	private:
		map<int, vector< pair<int,bool> > > table;
		list<int> path;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes,edges,a,b;
	cin>>nodes;
	cin>>edges;
	EulerianGraph eg(nodes);
	while(edges-- && cin>>a>>b) eg.connectNodes(a,b);
	eg.printEulerianPath();
	return 0;
}

/*

5
8
0 1
0 2
1 2
1 3
1 4
2 4
2 3
3 4

*/