#include <bits/stdc++.h>

using namespace std;

struct Node{
	bool black;
	vector<Node*> children;
	Node(bool color = false){
		this->black = color;
		for(int i = 0; i < 4; i++)
			children.emplace_back(nullptr);
	}
};

class QuadTree{
	public:
		QuadTree(){
			this->root = new Node();
		}

		void insertPreorder(string &preorder){
			this->preorder = preorder;
			index = 0;
			if(preorder[0] == 'f')
				root->black = true;
			mergeTree(root);
		}

		int blackPixels(){
			int pixels = 0;
			queue<pair<Node*, int>> order;
			order.push(make_pair(root, 32));
			while(!order.empty()){
				auto node = order.front().first;
				int units = order.front().second;
				order.pop();
				if(node->black){
					pixels += pow(units, 2);
				}else{
					for(int i = 0; i < 4; i++){
						if(node->children[i] != nullptr)
							order.push(make_pair(node->children[i], units >> 1));
					}
				}
			}
			return pixels;
		}

	private:
		Node *root;
		string preorder;
		int index;
		void mergeTree(Node *parent){
			++index;
			int blacks = 0;
			for(int i = 0; i < 4; i++){
				if(parent->children[i] == nullptr)
					parent->children[i] = new Node();
				if(preorder[index] == 'p'){
					mergeTree(parent->children[i]);
				}else if(preorder[index] == 'f'){
					parent->children[i]->black = true;
					++index;
				}else{
					++index;
				}
				if(parent->children[i]->black) ++blacks;
			}
			if(blacks == 4) parent->black = true;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cases;
	string preorder1, preorder2;
	cin>>cases;
	while(cases-- && cin>>preorder1>>preorder2){
		QuadTree tree;
		tree.insertPreorder(preorder1);
		tree.insertPreorder(preorder2);
		cout<<"There are "<<tree.blackPixels()<<" black pixels.\n";
	}	
	return 0;
}
