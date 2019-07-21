#include <bits/stdc++.h>

using namespace std;

struct Node{
	char name;
	vector<Node*> adj;
	bool lastDigit;
	Node(int name, bool lastDigit = false){
		this->name = name;
		this->adj.assign(26, nullptr);
		this->lastDigit = lastDigit;
	}
};

class Trie{
	public:
		Trie(){
			this->root = new Node('+');
			this->consistent = true;
		}
		void insertPhone(string phone){
			if(!consistent) return;
			Node *digit = root;
			for(int i = 0; i < phone.length() && consistent; ++i){
				int index = (int)phone[i]-'0';
				if(digit->adj[index] == nullptr){
					digit->adj[index] = new Node(phone[i]);
				}else{
					if(digit->adj[index]->lastDigit){
						consistent = false;
					}
				}
				digit = digit->adj[index];
				if(i+1 == phone.length()){
					digit->lastDigit = true;
					if(hasNeighbors(digit)) consistent = false;
				}
			}
		}

		bool isConsistent(){
			return consistent;
		}
		void clear(){
			this->root = nullptr;
			this->root = new Node('+');
			this->consistent = true;
		}
	private:
		Node *root;
		bool consistent;
		bool hasNeighbors(Node *node){
			for(int i = 0; i < node->adj.size(); ++i){
				if(node->adj[i] != nullptr) return true;
			}
			return false;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, numPhones;
	string phone;
	Trie agenda;
	cin>>t;
	while(t-- && cin>>numPhones){
		agenda.clear();
		while(numPhones-- && cin>>phone){
			agenda.insertPhone(phone);
		}
		cout<<(agenda.isConsistent() ? "YES\n" : "NO\n");
	}
	return 0;
}
