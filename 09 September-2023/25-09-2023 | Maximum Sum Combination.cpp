class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int, pair<int,int>>>maxHeap;
        maxHeap.push({A[N-1] + B[N-1] , {N-1, N-1}});

        set<pair<int,int>>myset;
        myset.insert({N-1 , N-1});

        vector<int> result;

        while(K>0)
        {
            pair<int, pair<int,int>> top = maxHeap.top();

            maxHeap.pop();
            int sum = top.first;
            int x = top.second.first;
            int y = top.second.second;

            result.push_back(sum);

            if(myset.find({x-1, y}) == myset.end()) {
                maxHeap.push({A[x-1] + B[y] , {x-1, y}});
                myset.insert({x-1, y});
            }

            if(myset.find({x, y-1}) == myset.end()) {
                maxHeap.push({A[x] + B[y-1] , {x, y-1}});
                myset.insert({x, y-1});
            }

            K-=1;
        }
        return result;
    }
};
