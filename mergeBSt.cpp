Node *newNode(int val){
    Node *n = new Node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(Node *root, int val){
    // if(root == NULL)
    if(val < root->data){
        if(root->left)
            insert(root->left, val);
        else{
            n = newNode(val);
            root->left = n;
        }
    }
    else{
        if(root->right)
            insert(root->right, val);
        else{
            n = newNode(val);
            root->right = n;
        }
    }
}

void recur(Node *root1, Node *root2){
    if(root2 == NULL)
        return;
    merge(root1, root2->left);
    insert(root1, root2->val);
    merge(root1, root2->right);
}

void merge(Node *root1, Node *root2)
{
    recur(root1, root2);
}














