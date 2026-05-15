class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // integer that appear twice would eventually have the 1s bit cancel
        int ans = 0;
        for(int i : nums) ans ^= i;
        return ans;
    }
};
