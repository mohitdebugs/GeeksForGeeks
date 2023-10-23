class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n , 0);
	    int sum=0 ;
	    for(int i = 0;i<n;++i) 
	    {
	        dp[i] = arr[i];
	        for(int j=i-1;j>=0;j--) 
	        {
	            if(arr[j] < arr[i])
	                dp[i] = max(dp[i] ,  arr[i] + dp[j]);
	        } 
	        sum= max(sum,dp[i]);
	    }
	    return sum;
	}  
};
