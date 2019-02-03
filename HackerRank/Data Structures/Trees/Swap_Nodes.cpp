#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data,level;
	Node *left,*right;
	Node(int data,int level=1):data(data),level(level),left(NULL),right(NULL){}
};

class Tree{
public:
	vector<Node*> nodesArray;
	Node *root;
	Tree(){
		root = new Node(1);
		nodesArray.push_back(root);
	}
	void inorder(){
		Node *temp = root;
		inorder(temp);
		cout<<endl;
	}
	void swapNodes(const int &k){
		Node *temp = root;
		swapNodes(temp,k);
		inorder();
	}
private:
	void inorder(Node *node){
		if(node!=NULL){
			inorder(node->left);
			cout<<node->data<<" ";
			inorder(node->right);
		}
	}
	void swapNodes(Node *node,const int &k){
		if(node!=NULL){
			if(node->level % k==0){
				swap(node->left,node->right);
			}
			swapNodes(node->left,k);
			swapNodes(node->right,k);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodes,l,r,pos=0;
	Tree t;
	cin>>nodes;
	while(nodes-- && cin>>l>>r){
		if(l!=-1){
			Node *node = new Node(l,t.nodesArray[pos]->level+1);
			t.nodesArray[pos]->left = node;
			t.nodesArray.push_back(node);
		}
		if(r!=-1){
			Node *node = new Node(r,t.nodesArray[pos]->level+1);
			t.nodesArray[pos]->right = node;
			t.nodesArray.push_back(node);
		}
		++pos;
	}
	int q,k;
	cin>>q;
	while(q--){
		cin>>k;
		t.swapNodes(k);
	}
	return 0;
}