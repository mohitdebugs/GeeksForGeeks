class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        if(root==NULL)
        {
            return {};
        }
        vector<int>v;
        inorder(root,K,v);
        int size=v.size();
        return v.at(size-K);
    }
    void inorder(Node*root,int K, vector<int>&v)
    {
        if(root!=NULL)
        {
            inorder(root->left,K,v);
            v.push_back(root->data);
            inorder(root->right,K,v);
        }
    }
};
