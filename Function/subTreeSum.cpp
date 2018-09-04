int countUtil(Node *root){
    if(root == NULL)
        return 0;
    int ls = countUtil(root->left);
    int rs = countUtil(root->right);
    return ls + rs + root->data;
}

int countSubtreesWithSumX(Node* root, int x)
{
	if(!root)
        return 0;

	if(countUtil(root) == x)
        return countSubtreesWithSumX(root->left, x)+countSubtreesWithSumX(root->right, x)+1;
    else
        return countSubtreesWithSumX(root->left, x)+countSubtreesWithSumX(root->right, x);
}