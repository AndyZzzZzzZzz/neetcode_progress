class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // travel from the station that give you the biggest gas cost diff
        int n = gas.size();
        vector<int> diff(n, 0);
        for(int i{}; i < n; ++i) diff[i] = gas[i] - cost[i];
        
        // track as well go
        int roll= {}, curr = {}, res = {};
        for(int i{}; i < n; ++i) {
            roll += diff[i];
            curr += diff[i];
            if(curr < 0) {curr = 0; res = (i+1)%n;}
        }
        if(roll < 0) return -1;
        return res;
    }
};
