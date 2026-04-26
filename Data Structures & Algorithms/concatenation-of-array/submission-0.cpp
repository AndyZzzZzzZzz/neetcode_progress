class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int> ans(nums.size()*2);

        for(int i{}; i < nums.size() *2; ++i) ans[i] = nums[i%nums.size()];
        return ans;
    }
};