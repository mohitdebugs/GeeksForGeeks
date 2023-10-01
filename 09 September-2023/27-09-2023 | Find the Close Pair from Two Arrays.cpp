class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i=n-1,j=0,diff=INT_MAX,ans1=-1,ans2=-1,sum;
        while(i>=0&&j<m)
        {
            sum=arr[i]+brr[j];
            if(abs(sum-x)<diff)
            {
                diff=abs(sum-x);
                ans1=arr[i];
                ans2=brr[j];
            }

            if(sum<x)
                j++;
            else if(sum==x)
                return {ans1,ans2};
            else 
                i--;
        }

        return {ans1,ans2};
    }
};
