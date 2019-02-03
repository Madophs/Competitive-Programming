#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
	int height;
	Node(int data):data(data),left(NULL),right(NULL),height(1){}
};

class AVLTree{
private:
	Node *root;
	void preorder(Node *node){
		if(node !=NULL){
			cout<<node->data<<" ";
			preorder(node->left);
			preorder(node->right);
		}
	}
	int getHeight(Node *node){
		if(node == NULL)return 0;
		return node->height;
	}
	int getBalance(Node *node){
		if(node == NULL) return 0;
		return getHeight(node->left) - getHeight(node->right);
	}
	Node *rightRotation(Node *node){
		Node *left = node->left;
		Node *rightChild = left->right;
		left->right = node;
		node->left = rightChild;
		node->height = 1 + max(getHeight(node->left),getHeight(node->right));
		left->height = 1 + max(getHeight(left->left),getHeight(left->right));
		return left; 
	}
	Node *leftRotation(Node *node){
		Node *right = node->right;
		Node *leftChild = right->left;
		right->left = node;
		node->right = leftChild;
		node->height = 1 + max(getHeight(node->left),getHeight(node->right));
		right->height = 1 + max(getHeight(right->left),getHeight(right->right));
		return right;
	}

	Node *minValueNode(Node *node){
		Node *current = node;
		if(current->left) current = current->left;
		return current;
	}
	Node *insert(Node *node, int data){
		if(node == NULL){
			return new Node(data);
		}else if(data < node->data){
			node->left = insert(node->left,data);
		}else if(data > node->data){
			node->right = insert(node->right,data);
		}else{
			return node;
		}
		node->height = 1 + max(getHeight(node->left),getHeight(node->right));
		int balance = getBalance(node);
		// left left case
		if(balance > 1  && data < node->left->data){
			return rightRotation(node);
		}
		//right right case
		if(balance < -1 && data > node->right->data){
			return leftRotation(node);
		}
		// left right case
		if(balance > 1 && data > node->left->data){
			node->left = leftRotation(node->left);
			return rightRotation(node);
		}
		// right left case
		if(balance < -1 && data < node->right->data){
			node->right = rightRotation(node->right);
			return leftRotation(node);
		}
		return node;
	}
	Node *removeNode(Node *node,int data){
		if(node==NULL)return node;
		if(data < node->data){
			node->left = removeNode(node->left,data);
		}else if(data > node-> data){
			node->right = removeNode(node->right,data);
		}else{
			if(node->left == NULL || node->right == NULL){
				Node *temp = node->left?node->left:node->right;
				if(temp != NULL){
					*node = *temp;
					free(temp);
				}else{
					temp = root;
					root = NULL;
				}
			}else{
				Node *temp = minValueNode(node->right);
				node->data = temp->data;
				root->right = removeNode(node->right,temp->data);
			}
		}
		if(node == NULL) return node;
				node->height = 1 + max(getHeight(node->left),getHeight(node->right));
		int balance = getBalance(node);
		// left left case
		if(balance > 1  && getBalance(node->left)>=0){
			return rightRotation(node);
		}
		//right right case
		if(balance < -1 && getBalance(node->right)<=0){
			return leftRotation(node);
		}
		// left right case
		if(balance > 1 && getBalance(node->left)<0){
			node->left = leftRotation(node->left);
			return rightRotation(node);
		}
		// right left case
		if(balance < -1 && getBalance(node->right) > 0){
			node->right = rightRotation(node->right);
			return leftRotation(node);
		}
		return node;
	}
public:
	AVLTree():root(NULL){}
	void insert(int data){
		root =  insert(root,data);
	}
	void preorder(){
		Node *node = root;
		preorder(node);
		cout<<endl;
	}
	void removeNode(int data){
		root = removeNode(root,data);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,v;
	AVLTree tree;
	cin>>n;
	while(n--){
		cin>>v;
		tree.insert(v);
	}
	tree.preorder();
	int rm;
	cin>>rm;
	while(rm--){
		cin>>v;
		tree.removeNode(v);
	}
	tree.preorder();
	return 0;
}

/*

5
30 35 5 32 40


9
13 10 5 11 4 6 15 16 7
*/