class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
    int h = 0;
    if(root != NULL)
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight + 1;
    }
    return h;
    }
};
