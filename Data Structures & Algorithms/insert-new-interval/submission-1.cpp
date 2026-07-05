class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.empty()) return {newInterval};
        int n = intervals.size();
        vector<vector<int>> ans;

        bool flag = false;
        for(int i{}; i < n; ++i) {
            auto& curr = intervals[i];
            if(!flag) {
                if(newInterval[1] < curr[0]) {ans.push_back(newInterval); flag = true; ans.push_back(curr); }
                else if(newInterval[0] > curr[1]) ans.push_back(curr);
                else {
                    newInterval[0] = min(newInterval[0], curr[0]);
                    newInterval[1] = max(newInterval[1], curr[1]);
                }
            }else{
                ans.push_back(curr);
            }
        }

        if(!flag) ans.push_back(newInterval);
        return ans;


    }
};
