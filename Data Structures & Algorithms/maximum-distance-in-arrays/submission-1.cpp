class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        

        int gmax= arrays[0].back(), gmin = arrays[0][0];
        int ans = 0;

        for(int i{1}; i < arrays.size(); ++i) {
            int l = arrays[i][0];
            int r = arrays[i].back();
            ans = max({ans, abs(l - gmax), abs(r - gmin)});
            gmax = max(gmax, r);
            gmin = min(gmin, l);
        } 

        return ans ;
    }
};
