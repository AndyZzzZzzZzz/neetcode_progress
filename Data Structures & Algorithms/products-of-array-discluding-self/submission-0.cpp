class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // O(N) time with O(1) memory
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        for(int i=1; i < n; ++i) ans[i] = ans[i-1] * nums[i];

        for(int i=n-1; i >=0; --i)
        {
            // edge case when we are at both end
            if(i == 0) ans[i] = nums[i+1];
            else if(i == n-1) ans[i] = ans[i-1];
            else ans[i] = ans[i-1] * nums[i+1];
            if(i < n-1) nums[i] = nums[i] * nums[i+1];
        }
        return ans;
    }
};
