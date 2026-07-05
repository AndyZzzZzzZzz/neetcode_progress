class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int begin = intervals[0][0], end = intervals[0][1];

        for(auto& in : intervals) {
            if(end < in[0]) {
                ans.push_back({begin, end});
                begin = in[0]; end = in[1];
            } else {
                begin = min(in[0], begin);
                end = max(in[1], end);
            }
        }

        ans.push_back({begin, end});
        return ans;
    }
};
