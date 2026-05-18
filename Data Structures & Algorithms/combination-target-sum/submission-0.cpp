class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        function<void(int, int, vector<int>&)> dfs = [&](int i, int remain, vector<int>& v)
        {
          
            if(remain == 0) 
            {
                ans.push_back(v); return;
            }
            
            if(remain < 0 || i >= nums.size()) return;


            v.push_back(nums[i]);
            dfs(i, remain - nums[i], v);
            v.pop_back();
            dfs(i +1, remain, v);
        };
        vector<int> v;
        dfs(0, target, v);
        return ans;
    }
};
