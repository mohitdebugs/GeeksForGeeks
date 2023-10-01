class Solution{
public:
    string findLargest(int N, int S){
        if(S == 0 && N==1)  return "0";
        if(S == 0 && N > 1) return "-1";
        string ans = "";
        for(int i{0}; i < N; ++i){
            if(S > 9){
                ans += '9';
                S -= 9;
            }
            else{
                ans +=(S + '0');
                S = 0;
            }
        }
        return S == 0 ? ans : "-1";
    }
};
