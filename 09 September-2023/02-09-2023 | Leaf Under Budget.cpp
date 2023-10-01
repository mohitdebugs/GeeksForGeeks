class Solution
{
public:
    int getCount(Node *root, int k)
    {
        queue< pair< Node*, int >> c;
        c.push({root, 1});
        int cnt = 0;

        while (!c.empty() && k > 0) {
            auto nd = c.front().first;
            int lv = c.front().second;
            c.pop();

            if (!nd->left && !nd->right) {
                if (lv>k)
                    return cnt;

                ++cnt;
                k -= lv;
            } else {
                if (nd->left)
                    c.push({nd->left, lv+1});
                if (nd->right)
                    c.push({nd->right, lv+1});
            }
        }

        return cnt;
    }
};
