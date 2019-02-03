#include <bits/stdc++.h>

using namespace std;

enum Color{
	black,red	
};

struct Node{
	int data;
	Color color;
	Node *left,*right,*parent;
	Node(int data){
		this->data = data;
		left = right = parent = nullptr;
		color = red;
	}
};

class RedBlack{
private:
	Node *root;
	Node * insert(Node *root, Node *node){
		if(root==NULL){
			return node;
		}else if(node->data < root->data){
			root->left = insert(root->left,node);
			root->left->parent = root;
		}else if(node->data > root->data){
			root->right = insert(root->right,node);
			root->right->parent = root;
		}
		return root;
	}
	void preorder(Node *node){
		if(node != NULL){
			cout<<node->data<<(node->color?"->r ":"->b ");
			preorder(node->left);
			preorder(node->right);
		}
	}
	void rightRotation(Node *&node, Node *&root){
		Node *leftChild = node->left;
		Node *rightLeftChild = leftChild->right;
		leftChild->right = node;
		leftChild->parent = node->parent;
		node->left = rightLeftChild;
		if(rightLeftChild!=NULL) rightLeftChild->parent = node;
		if(leftChild->parent == NULL){
			root = leftChild;
		}else{
			Node *parentNode = leftChild->parent;
			if(parentNode->left!=NULL && parentNode->left==node){
				parentNode->left = leftChild;
			}else{
				parentNode->right = leftChild;
			}
		}
		node->parent = leftChild;
	}
	void leftRotation(Node *&node, Node *&root){
		Node *rightChild = node->right;
		Node *leftRightChild = rightChild->left;
		rightChild->left = node;
		rightChild->parent = node->parent;
		node->right = leftRightChild;
		if(leftRightChild!=NULL) leftRightChild->parent = node;
		if(rightChild->parent == NULL){
			root = rightChild;
		}else{
			Node *parentNode = rightChild->parent;
			if(parentNode->left!=NULL && parentNode->left==node){
				parentNode->left = rightChild;
			}else{
				parentNode->right = rightChild;
			}
		}
		node->parent = rightChild;
	}
	void fix(Node *&root, Node *&node){
		Node *uncleNode = nullptr,*parentNode = nullptr,*grandparent = nullptr;
		while(node!=root && node->color!=black && node->parent->color==red){
			parentNode = node->parent;
			grandparent = node->parent->parent;
			if(parentNode == grandparent->left){
				uncleNode = grandparent->right;
				if(uncleNode!=NULL && uncleNode->color == red){
					uncleNode->color = black;
					parentNode->color = black;
					grandparent->color = red;
					node = grandparent;
				}else{
					if(node == parentNode->right){
						leftRotation(parentNode,root);
						node = parentNode;
						parentNode = node->parent;
					}
					rightRotation(grandparent,root);
					swap(parentNode->color,grandparent->color);
					node = parentNode;
				}
			}else{
				uncleNode = grandparent->left;
				if(uncleNode!=NULL && uncleNode->color==red){
					uncleNode->color = black;
					parentNode->color = black;
					grandparent->color = red;
					node = grandparent;
				}else{
					if(node == parentNode->left){
						rightRotation(parentNode,root);
						node = parentNode;
						parentNode = node->parent;
					}
					leftRotation(grandparent,root);
					swap(parentNode->color, grandparent->color);
					node = parentNode;
				}
			}
		}
		root->color = black;
	}
public:
	RedBlack():root(NULL){}
	void insert(int data){
		Node *node = new Node(data);
		root = insert(root,node);
		fix(root,node);
	}
	void preorder(){
		Node *aux = root;
		preorder(aux);
		cout<<endl;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,val;
	cin>>size;
	RedBlack t;
	while(size--){
		cin>>val;
		t.insert(val);
		t.preorder();
	}
	t.preorder();
	return 0;
}

/*

4
10 5 15 3

8
10 8 9 4 15 12 3 11

99
80 100 65 30 200 500 90 150 170
*/