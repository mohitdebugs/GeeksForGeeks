class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        const int mod = 1e9 + 7;
        
        long long one, two, three;
        one = 1;
        two = 2;
        three = 4;
        
        if(n == 1)
            return one;
        else if(n == 2)
            return two;
        else if(n == 3)
            return three;
        else{
            for(int i = 4; i < n + 1; i++){
                long long next = (one + two + three) % mod;
                one = two;
                two = three;
                three = next;
            }
        } 
        return three;
    }
};
