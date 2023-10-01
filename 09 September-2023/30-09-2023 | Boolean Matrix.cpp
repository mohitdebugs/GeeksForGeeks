class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &matr)
    {
        int n = matr.size();
        int m = matr[0].size();
        
        int r[n] = {0};
        int c[m] = {0};
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(matr[i][j] == 1)
                {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        
        for(int i = 0 ; i<n;  i++)
        {
            if(r[i] == 1)
            {
                for(int j = 0 ; j <m ; j++)
                {
                    matr[i][j] = 1;
                }
            }
        }
        for(int i = 0 ; i<m;  i++)
        {
            if(c[i] == 1)
            {
                for(int j = 0 ; j <n ; j++)
                {
                    matr[j][i] = 1;
                }
            }
        }
    }
};
