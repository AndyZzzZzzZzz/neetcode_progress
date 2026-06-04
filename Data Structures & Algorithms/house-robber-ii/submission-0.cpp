class Solution {
public:
    int dp(vector<int> & nums, int start, int end)
    {
        int skip = nums[start];
        int take = max(nums[start], nums[start +1]);

        for(int i{start +2}; i < end; ++i)
        {
            int c = max(nums[i] + skip, take);
            skip = take; 
            take = c;
        }
        return max(skip, take);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(dp(nums, 0, nums.size()-1), dp(nums, 1, nums.size()));
    }
};
