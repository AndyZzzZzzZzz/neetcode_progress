class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int min_prev = 0;
        int min_prev_prev = 0;

        for(int i=2; i <= n; ++i)
        {

            // cost to jump from i-1 and i-2
            int curr = min(min_prev + cost[i-1], min_prev_prev + cost[i-2]);

            min_prev_prev = min_prev;
            min_prev = curr;
        }

        return min_prev;
    }
};
