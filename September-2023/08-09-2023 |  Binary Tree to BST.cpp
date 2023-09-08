class Solution{
  public:
    Node *binaryTreeToBST (Node *root)
    {
        vector<Node*> n;
        inorder(root, n);
        vector<int> values;
        
        for (auto node : n){
            values.push_back(node->data);}

        sort(values.begin(), values.end());

        for (int i = 0; i < n.size(); ++i){
            n[i]->data = values[i];}

        return root;
    }
    void inorder(Node *root, vector<Node*>& n) 
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, n);
        n.push_back(root);
        inorder(root->right, n);
    }

};
