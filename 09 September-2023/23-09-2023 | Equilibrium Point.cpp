class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
    
        if(n==1) 
            return 1;
        long long t[n];
        for(int i=0; i<n; i++)
        {
            t[i] = a[i];
        }
        for(int i=1; i<n; i++)
        {
            a[i] += a[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            t[i] += t[i+1];
            if(a[i]==t[i]) 
                return i+1;
        }
        return -1;
    }

};
