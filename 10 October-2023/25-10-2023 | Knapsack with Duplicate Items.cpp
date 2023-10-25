class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,-1);
        return solve(N,W,val,wt,dp);
    }
    int solve(int N, int W, int val[], int wt[] , vector<int> &dp){
        if(W == 0)
            return 0;
        if(W<0)
            return INT_MIN;
        if(dp[W] != -1)
            return dp[W];
        int maxprofit = 0;
        for(int i=0;i<N;i++){
            int include = 0;
            include = val[i] + solve(N,W-wt[i],val,wt,dp);
            maxprofit = max(include,maxprofit);
        }
        dp[W] = maxprofit;
        return dp[W];
    }
    
};
