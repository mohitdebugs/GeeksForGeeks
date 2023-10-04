class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n){
            int m=n%26;
            n/=26;
            if(m==0){
                ans+='Z';
                n--;
            }
            else{
                char c='A'+m-1;
                ans+=c;
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
