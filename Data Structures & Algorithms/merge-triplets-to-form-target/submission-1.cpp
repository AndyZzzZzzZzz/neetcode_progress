class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // linear scan + update
        sort(triplets.begin(), triplets.end());
        int a{}, b{}, c{};

        for(auto& t : triplets) {
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            a = max(a, t[0]);
            b = max(b, t[1]);
            c = max(c, t[2]);
            if(a == target[0] && b==target[1] && c == target[2]) return true;
        }
        return false;
    }
};
