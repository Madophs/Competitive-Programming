#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

        /*
        class Node {
            public:
                int data;
                Node *left;
                Node *right;
                Node(int d) {
                    data = d;
                    left = NULL;results
                    right = NULL;
                }
        };

        */

        struct NodeCovering{
            int covering;
            Node *p;
            NodeCovering(int c,Node *p):covering(c),p(p){}
        };

        void topView(Node *root) {
          int minCovering = 0, maxCovering = 0;
          queue<NodeCovering> q;
          deque<int> ans;
          ans.push_front(root->data);
          q.push(NodeCovering(0,root));
          while(!q.empty()){
              NodeCovering node = q.front();
              q.pop();
              if(node.covering < minCovering){
                  ans.push_front(node.p->data);
                  minCovering = node.covering;
              }else if(node.covering > maxCovering){
                  ans.push_back(node.p->data);
                  maxCovering = node.covering;
              }
              if(node.p->left){
                  q.push(NodeCovering(node.covering-1,node.p->left));
              }
              if(node.p->right){
                  q.push(NodeCovering(node.covering+1,node.p->right));
              }
          }
          while(!ans.empty()){
              cout<<ans.front()<<" ";
              ans.pop_front();
          }
        }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
