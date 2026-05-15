class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // calculate time each car reach destination
        // use stack to form fleet and merge cars together

        vector<pair<int,int>> pairs;
        for(int i{}; i < position.size(); ++i) pairs.push_back({position[i], speed[i]});
        sort(pairs.begin(), pairs.end());

        double prev = -1.0;
        int ans = 0;
        for(int i=position.size() - 1; i >= 0; --i)
        {
            int p = pairs[i].first;
            int s = pairs[i].second;

            double time = (double)(target - p) / (double)s;
            
            // arived earlier
            if(prev > 0 && time <= prev)
            {
                // merge
                continue;
            }
            else
            {
                ans++;
                prev = time;
            }
        }
        return ans;
    }
};
