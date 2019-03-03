#include <bits/stdc++.h>
#define EMPTY -1e9

using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int data):data(data),left(NULL), right(NULL){}
};

class Tree{
	public:
		Tree(){
			this->root = new Node(EMPTY);
			this->correct = true;
		}
		void insertNode(int data, string ins){
			Node *aux = root;
			for(int i = 0; i<ins.length(); i++){
				if(ins[i] == 'L'){
					if(aux->left == NULL) aux->left = new Node(EMPTY);
					aux = aux->left;
				}else{
					if(aux->right == NULL) aux->right = new Node(EMPTY);
					aux = aux->right;
				}
			}
			aux->data = data;
		}
		void generateLevelOrder(){
			if(!correct) return;
			queue<Node*> q;
			q.push(root);
			while(!q.empty()){
				Node *temp = q.front();
				q.pop();
				if(temp->data == EMPTY){
					correct = false;
					break;
				}
				order.push_back(temp->data);
				if(temp->left!=NULL) q.push(temp->left);
				if(temp->right!=NULL) q.push(temp->right);
			}
		}
		void printLevelOrder(){
			if(correct){
				for(int x = 0; x<order.size(); x++){
					if(x>0)cout<<" ";
					cout<<order[x];
				}
				cout<<'\n';
			}else{
				cout<<"not complete\n";
			}
		}
	private:
		Node *root;
		bool correct;
		vector<int> order;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	while(cin>>line){
		if(line == "()"){
			cout<<"no complete\n";
			continue;
		}
		bool specified = true;
		unordered_set<string> uniqueNodes;
		Tree t;
		do{
			if(specified){
				string temp = line.substr(1,line.length()-2),value,ins="";
				stringstream ss(temp);
				int data;
				if(temp[0]!=','){
					getline(ss,value,',');
					data = atoi(value.c_str());
					if(getline(ss,value,',')) ins = value;
					if(uniqueNodes.find(ins) == uniqueNodes.end()){
						uniqueNodes.insert(ins);
					}else{
						specified = false;
					}
				}else{
					specified = false;
				}
				if(specified){
					t.insertNode(data, ins);
				}
			}
		}while(cin>>line && line!="()");
		if(specified){
			t.generateLevelOrder();
			t.printLevelOrder();
		}else{
			cout<<"not complete\n";
		}
	}
	return 0;
}