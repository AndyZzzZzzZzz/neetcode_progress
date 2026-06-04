class Solution {
public:
    int countSubstrings(string s) {
        // 2d dp approach
        // dp[i][j] ==  substring i, j is palindormic
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int total = 0;

        for(int i=0; i < n; ++i)
        {
            dp[i][i] = true;
            total++;
        }

        // iterate via length
        for(int len=2; len <= n; ++len)
        {
            for(int l=0; l <= n - len;  ++l)
            {
                int r = l + len -1;
                if(s[l]==s[r] && (len <= 2 || dp[l+1][r-1]))
                {
                    total++;
                    dp[l][r] = true;
                }
            }
        }
        return total;
    }
};
