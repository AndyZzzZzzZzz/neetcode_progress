class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // track min ways to make amount x
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        
        sort(coins.begin(), coins.end());
        for(int a{1}; a <= amount; a++) {

            for(int c : coins) {

                if(a - c < 0) break;
                dp[a] = min(dp[a], dp[a - c]+1);
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
