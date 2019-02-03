/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


node *newNode(int val){
    node *temp = new node();
    temp->val = val;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->ht = 0;
    return temp;
}
int getHeight(node *root){
    if(root==nullptr) return -1;
    return root->ht;
}
int getBalance(node *a, node *b){
    return getHeight(a)-getHeight(b);
}
node * leftRotation(node *pivot){
    node *right = pivot->right;
    node *leftChild = right->left;
    right->left = pivot;
    pivot->right = leftChild;
    pivot->ht = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    right->ht = 1 + max(getHeight(right->left), getHeight(right->right));
    return right;
}
node * rightRotation(node * pivot){
    node *left = pivot->left;
    node *rightChild = left->right;
    left->right = pivot;
    pivot->left = rightChild;
    pivot->ht = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    left->ht = 1 + max(getHeight(left->left), getHeight(left->right));
    return left;
}
node * insertNode(node * root,int val){
    if(root==NULL){
        return newNode(val);
    }else if(val < root->val){
        root->left = insertNode(root->left,val);
    }else{
        root->right = insertNode(root->right,val);
    }
    root->ht = 1 + max(getHeight(root->left),getHeight(root->right));
    int balance = getBalance(root->left, root->right);
    if(balance > 1 && val < root->left->val){
        return rightRotation(root);
    }
    if(balance < -1 && val > root->right->val){
        return leftRotation(root);
    }
    if(balance > 1 && val > root->left->val){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if(balance < -1 && val < root->right->val){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

node * insert(node * root,int val)
{
    root = insertNode(root,val);
    return root;
}


