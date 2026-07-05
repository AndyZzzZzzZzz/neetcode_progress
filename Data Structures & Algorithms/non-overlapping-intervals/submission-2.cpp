class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];

        int count{0};
        for(int i{1}; i < intervals.size(); ++i) {
            auto& p = intervals[i];
            if(p[0] >= end) {
                start = p[0]; 
                end = p[1];
            } else {
                count++;
                if(p[1] < end) {
                    start = p[0];
                    end = p[1];
                }
            }
        }
        return count;
    }
};
