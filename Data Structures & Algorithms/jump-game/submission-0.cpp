class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int reach = n -1;

        for(int i{n-1}; i >= 0; --i) {
            if(nums[i] >= (reach - i)) reach = i;
        }
        return reach == 0;
    }
};
