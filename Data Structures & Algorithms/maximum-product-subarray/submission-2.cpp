class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0];
        int curr_max = nums[0], curr_min = nums[0];

        for(int i{1}; i < nums.size(); ++i) {
            int pos = max({nums[i], curr_max * nums[i], curr_min * nums[i]});
            int neg = min({nums[i], curr_max * nums[i], curr_min * nums[i]});
            ans = max({nums[i], ans, pos});
            curr_max = pos; curr_min = neg;
        }
        return ans;

    }
};
