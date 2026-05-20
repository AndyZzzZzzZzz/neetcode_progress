class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        function<void(int, vector<int>&, int)> dfs = [&](int i, vector<int>& curr, int remain){

            if(remain == 0)
            {
                ans.push_back(curr); return;
            }
            if(i >= candidates.size() || remain < 0) return;


            for(int j=i; j < candidates.size(); ++j)
            {
                if(j > i && candidates[j] == candidates[j-1]) continue;
                curr.push_back(candidates[j]);
                dfs(j +1, curr, remain - candidates[j]);
                curr.pop_back();
            }
        };
        vector<int> curr;
        dfs(0, curr, target);
        return ans;
    }
};
