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
	unordered_map<string,int> diccionary;
	int id = 0;
	string prefix="";

	void add(string name){
		if(diccionary.find(name)==diccionary.end()){
			diccionary[name] = ++id;
		}else{
			diccionary.find(name)->second = -1;
            if(prefix.empty()){
                prefix = name;
            }
		}
		unordered_map<char,Node*>::iterator aux = table.find(name[0]);
		if(aux==table.end()){
			table[name[0]] = new Node();
		}
		aux = table.find(name[0]);
		for(int x=1; x<name.length(); x++){
			auto temp = aux->second->adj.find(name[x]);
			if(temp == aux->second->adj.end()){
				aux->second->adj[name[x]] = new Node();
			}
			aux = aux->second->adj.find(name[x]);
		}
		aux->second->count++;
        if(aux->second->adj.size()>0){
            if(prefix.empty()){
                prefix = name;
            }
        }
	}

	void findOcurrences(string name){
		if(!prefix.empty()) return;
		int cont = 0;
		bool found = true;
		unordered_map<char,Node*>::iterator aux = table.find(name[0]);
		string subtring = "";
		cont = aux->second->count;
		subtring += aux->first;
		if(cont>=1){
			auto temp = diccionary.find(subtring);
			if(prefix.empty() && temp->second!=id){
				prefix = name;
			}
		}
		for(int x=1; x<name.length(); x++){
			auto temp = aux->second->adj.find(name[x]);
			aux = aux->second->adj.find(name[x]);
			subtring+=aux->first;
			cont = aux->second->count;
			if(cont>=1 && x+1<name.length()){
				auto tempSubtring = diccionary.find(subtring);
				if(prefix.empty()){
					prefix = name;
				}
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string word;
	Trie t;
	cin>>n;
	while(n-- && cin>>word){
		t.add(word);
		t.findOcurrences(word);
	}
	if(t.prefix.empty()){
		cout<<"GOOD SET\n";
	}else{
		cout<<"BAD SET\n"<<t.prefix<<endl;
	}
	return 0;
}

