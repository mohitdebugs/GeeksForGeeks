class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int a= nums1.size();
        int b= nums2.size();
        vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MIN));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                int dot = nums1[i-1] * nums2[j-1];
                dp[i][j] = max({dot + max(dp[i-1][j-1],0) , dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[a][b];
    }
};
