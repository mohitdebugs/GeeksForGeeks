class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector<int> v(2,0);
            d %= 16;
            v[0] = (n << d) | (n >> (16 - d));
            v[1] = (n >> d) | (n << (16 - d));
            v[0] &= (1 << 16) - 1;
            v[1] &= (1 << 16) - 1;
            return v;
        }
};
