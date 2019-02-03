#include <bits/stdc++.h>

using namespace std;

struct Node{
	unordered_map<char,Node*> adj;
	int count;
	Node():count(0){}
};

class Trie{
public:
	unordered_map<char, Node*> table;
	
	void add(string name){
		unordered_map<char,Node*>::iterator aux = table.find(name[0]);
		if(aux==table.end()){
			table[name[0]] = new Node();
		}
		aux = table.find(name[0]);
		aux->second->count++;
		for(int x=1; x<name.length(); x++){
			auto temp = aux->second->adj.find(name[x]);
			if(temp == aux->second->adj.end()){
				aux->second->adj[name[x]] = new Node();
			}
			++aux->second->adj.find(name[x])->second->count;
			aux = aux->second->adj.find(name[x]);
		}
	}

	int findOcurrences(string name){
		int cont = 0;
		bool found = true;
		unordered_map<char,Node*>::iterator aux = table.find(name[0]);
		if(aux == table.end()) return 0;
		cont = aux->second->count;
		for(int x=1; x<name.length(); x++){
			auto temp = aux->second->adj.find(name[x]);
			if(temp == aux->second->adj.end())return 0;
			aux = aux->second->adj.find(name[x]);
			cont = aux->second->count;
		}
		return cont;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string op,name;
	Trie t;
	cin>>n;
	while(n-- && cin>>op>>name){
		if(op=="add"){
			t.add(name);
		}else{
			cout<<t.findOcurrences(name)<<endl;
		}
	}
	return 0;
}