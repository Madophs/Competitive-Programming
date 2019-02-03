#include <bits/stdc++.h>

using namespace std;

struct vertex{
	vector<vertex*> adj;
	char name;
	int length;
	bitset<26> conexions;
	bool awake;
	vertex(char name,int length=-1, bool awake = false):name(name),length(length),awake(awake){}
};

class Neurons{
public:
	unordered_map<char,vertex*> table;

	void insertNeuron(char name, int length=-1, bool awake=false){
		if(table.find(name)!=table.end())return;
		table[name] = new vertex(name,length,awake);
	}

	void connectNeurons(char a, char b){
		insertNeuron(a);
		insertNeuron(b);
		auto n1 = table.find(a),n2 = table.find(b);
		n1->second->adj.push_back(n2->second),n2->second->adj.push_back(n1->second);
	}

	int bfs(string start, int &size){
		bitset<100> visited;
		bitset<100> awakening;
		queue<char> q;
		for(auto iter = start.begin(); iter!=start.end(); iter++){
			q.push(*iter);
			awakening.set(*iter);
		}
		int years=1;
		vector<char> newNeurons;
		while(!q.empty()){
			char neuron = q.front();
			q.pop();
			auto aux = table.find(neuron)->second;
			for(auto iter = aux->adj.begin(); iter!=aux->adj.end(); iter++){
				auto ref = *iter;
				if(!awakening.test(ref->name)){
					ref->length = years;
					ref->conexions.set(aux->name-'A');
					if(ref->conexions.count()==3){
						awakening.set(ref->name);
						ref->awake = true;
						newNeurons.push_back(ref->name);
					}
				}
			}
			if(q.empty() && !newNeurons.empty()){
				++years;
				for(auto temp = newNeurons.begin(); temp!=newNeurons.end(); temp++){
					q.push(*temp);
				}
				newNeurons.clear();
			}
		}
		if(table.size()!=size)return -1;
		int ans=0;
		for(auto iter = table.begin(); iter!=table.end(); iter++){
			auto ref = *iter;
			if(ref.second->awake){
				ans = max(ans,ref.second->length);
			}else{
				ans=-1;
				break;
			}
		}
		return ans;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	int n,q;
	string awake,connect;
	while(cin>>n){
		cin>>q;
		cin>>awake;
		Neurons neu;
		for(auto iter = awake.begin(); iter!=awake.end(); iter++)neu.insertNeuron(*iter,0,true);
		while(q--){
			cin>>connect;
			neu.connectNeurons(connect[0],connect[1]);
		}
		int ans = neu.bfs(awake, n);
		cout<<(ans==-1?"THIS BRAIN NEVER WAKES UP\n":"WAKE UP IN, "+to_string(ans)+", YEARS\n");
	}
	return 0;
}