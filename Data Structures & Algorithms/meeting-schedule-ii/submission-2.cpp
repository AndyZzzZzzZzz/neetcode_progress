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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s, e;
        for(auto & i : intervals) {
            s.push_back(i.start);
            e.push_back(i.end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int count{}, ans{};
        int start_ptr{}, end_ptr{};
        while(start_ptr < intervals.size()) {
            if(s[start_ptr] < e[end_ptr]) {
                count++;
                start_ptr++;
                ans = max(ans, count);
            }else {
                // a meeting finished 
                count--;
                end_ptr++;
            }
        }
        return ans;

        
    }
};
