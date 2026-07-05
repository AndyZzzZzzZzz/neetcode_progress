class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);
        for(unsigned int i{}; i <=n; ++i) 
        {
            ans[i] = std::popcount(i);
        }
        return ans;
    }
};
