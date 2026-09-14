class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        function<void(int, vector<int>&)> backtrack = [&](int pos, vector<int>& curr) {
            if(pos == n) { ans.push_back(curr); return; }
            backtrack(pos+1, curr);
            curr.push_back(nums[pos]);
            backtrack(pos+1, curr);
            curr.pop_back();
        };
        vector<int> curr;
        backtrack(0, curr);
        return ans;
    }
};
