class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, vector<bool>& choose) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr); return;
        }

        for(int i{}; i < nums.size(); ++i) {
            if(!choose[i]) {
                choose[i] = true;
                curr.push_back(nums[i]);
                backtrack(ans, nums, curr, choose);
                choose[i] = false;
                curr.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> choose(nums.size(), false);
        vector<int> curr;
        backtrack(ans, nums, curr, choose);
        return ans;
    }
};
