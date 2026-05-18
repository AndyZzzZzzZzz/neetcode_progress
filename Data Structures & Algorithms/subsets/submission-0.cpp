class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        function<void(int, vector<int>&)> dfs = [&](int i, vector<int>& v)
        {
            if(i == nums.size())
            {
                ans.push_back(v);
                return;
            }

            v.push_back(nums[i]);
            dfs(i + 1, v);
            v.pop_back();
            dfs(i +1, v);
        };
        vector<int> v;
        dfs(0, v);
        return ans;
    }
};
