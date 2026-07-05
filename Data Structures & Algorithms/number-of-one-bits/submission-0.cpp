class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i{}; i < 32; ++i) {
            int x = 1;
            x &= n;
            n >>= 1;
            if(x) ans++;
        }
        return ans;
    }
};
