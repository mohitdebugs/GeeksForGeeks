class Solution {
public:
    int minDeletions(string s) {
        vector<int> fre(26, 0);
        for (char a:s) {
            fre[a-'a']++;
        }
        sort(fre.begin(), fre.end());
        int delt = 0;
        for (int i = 24; i >= 0; i--) {
            if (fre[i] == 0) {
                break;
            }
            if (fre[i]>=fre[i + 1]) {
                int prev = fre[i];
                fre[i] = max(0, fre[i + 1] - 1);
                delt += prev - fre[i];
            }
        }
        return delt;
    }
};
