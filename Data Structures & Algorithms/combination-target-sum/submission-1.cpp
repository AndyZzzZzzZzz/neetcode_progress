class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        function<void(int, int, vector<int>&)> backtrack = [&](int i, int x, vector<int>& curr) {
            if(i == n && x == target) { ans.push_back(curr); return;}
            if(i == n || x > target) return;

            curr.push_back(nums[i]);
            backtrack(i, x+ nums[i], curr);   // same i
            curr.pop_back();
            backtrack(i + 1, x, curr);  
        };
        vector<int> curr;
        backtrack(0, 0, curr);
        return ans;
        
    }
};
