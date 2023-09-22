class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int i;
        vector<int> ans(2);
        ans[0]=-1;
        ans[1]=-1;
        for(i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                ans[0]=i;
                ans[1]=i;
                i++;
                break;
            }
        }
        for(i;i<n;i++)
        {
            if(arr[i]!=x)
            {
                ans[1]=i-1;
                break;
            }
        }
        if(arr[n-1]==x)
        {
            ans[1]=n-1;
        }
        return ans;
        
    }
};
