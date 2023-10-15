class Solution{
    
    public:
     
    Node* buildBalancedTree(Node* root)
    {
    	vector<int> ans;
    	inorder(root,ans);
    	return buildTree(ans,0,ans.size()-1);
    }
   
    void inorder(Node* root,vector<int>&ans)
    {
        if(root==NULL){
            return;
            }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    Node* buildTree(vector<int>&ans,int start,int end)
    {
        if(start>end){
            return NULL;
        }
        int mid=start+(end-start)/2;
        Node* parent=new Node(ans[mid]);
        parent->left=buildTree(ans,start,mid-1);
        parent->right=buildTree(ans,mid+1,end);
        return parent;
    }

};
