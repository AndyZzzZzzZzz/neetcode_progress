/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        vector<vector<int>> tmp;
        for(auto & i : intervals) tmp.push_back({i.start, i.end});
        sort(tmp.begin(), tmp.end());
        for(int i{1}; i < intervals.size(); ++i) if(tmp[i][0] < tmp[i-1][1]) return false;
        
        return true;
    }
};
