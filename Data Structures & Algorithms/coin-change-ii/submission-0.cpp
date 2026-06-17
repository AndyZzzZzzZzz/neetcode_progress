class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        // tack total amount of ways to make doller x
        vector<int> dp(amount +1, 0);
        dp[0] = 1;

        sort(coins.begin(), coins.end());
        for(int c : coins) {

            for(int x{1}; x <= amount; ++x) {
                if(x-c < 0) continue;
                dp[x] += dp[x-c];
            }
        }
        return dp[amount];
    }
};
