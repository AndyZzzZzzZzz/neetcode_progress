class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curr = 0;
        int count = 0;
        while(curr < nums.size()-1) {
            int l = nums[curr];
            int _max = 0;
            int nxt = curr;
            for(int r{1}; r <= l; ++r) {
                if(curr + r >= nums.size()-1) return count+1;
                if(curr + r + nums[curr + r] >= _max) {
                    //  Indices:  0  1  2  3  4  5  6
                    //  nums =   [3, 4, 1, 3, 0, 0, 1]
                    _max = curr + r + nums[curr + r];
                    nxt = curr+r;
                }
            }
            count ++;
            curr = nxt;
        }
        return count;
    }
};
