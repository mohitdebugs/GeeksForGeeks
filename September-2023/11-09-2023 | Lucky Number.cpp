class Solution{
public:
    bool isLucky(int n) {
        // code here
        int count=2;
        while(count<=n)
        {
            if(n%count == 0)
                return false;
            n=n-(n/count);
            count++;
        }
        return true;
    }
};
