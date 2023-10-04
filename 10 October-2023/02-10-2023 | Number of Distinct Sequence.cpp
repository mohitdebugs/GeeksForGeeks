class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.length();
        int mod = 1000000007;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        vector<int> v(26,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
            if(v[s[i-1]-'a']!=-1) dp[i]-=dp[v[s[i-1]-'a']];
            dp[i]%=mod;
            v[s[i-1]-'a']=i-1;
        }
        if(dp[n]<0) dp[n]+=mod;
        return dp[n]%mod;
	}
};
