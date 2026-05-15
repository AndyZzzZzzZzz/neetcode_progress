class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size();
        while(l <= r)
        {
            int m = (r - l)/2 + l;
            if(nums[m] == target) return m;
            if(nums[m] < target) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};
