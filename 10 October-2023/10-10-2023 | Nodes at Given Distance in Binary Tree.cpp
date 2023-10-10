class Solution
{
private:

public:

    void findPath(Node* root, int target, vector<Node*> &path, bool &found){
        if(!root || found == true) return;

        path.push_back(root);

        if(root->data == target){
            found = true;
            return;
        }

        findPath(root->left, target, path, found);
        findPath(root->right, target, path, found);

        if(!found){
            path.pop_back();
        }

    }

    void solve(Node* root, int len, vector<int> &ans, unordered_map<Node*, int> &vis){

        if(!root) return;

        if(len == 0){
            ans.push_back(root->data);
            return;
        }
        if(!vis[root->left])
            solve(root->left, len-1, ans, vis);

        if(!vis[root->right])
            solve(root->right, len-1, ans, vis);

    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {

        vector<Node*> path;
        bool found = false;
        findPath(root, target, path, found);

        if(!found) return {-1};

        int n = path.size();

        unordered_map<Node*, int> vis;

        vector<int> ans;
        int len = k;
        for(int i=n-1; i>=0; i--){
            if(i == n-k-1){
                ans.push_back(path[i]->data);
                break;
            }
            solve(path[i], len, ans, vis);
            vis[path[i]] = 1;
            len--;
        }

        sort(ans.begin(), ans.end());

        return ans;

    }
};
