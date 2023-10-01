class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        
        for(int i=1;i<n;i++)
        {
            if(i%2!=0)
            {
                int temp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
            }
        }
        
    }
};
