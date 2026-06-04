class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int take = nums[0];
        int skip = max(nums[0], nums[1]);

        for(int i=2; i < nums.size(); ++i)
        {
            int curr = max(take + nums[i], skip);
            take = skip;
            skip = curr; 
        }
        return max(skip, take);
    }
};
