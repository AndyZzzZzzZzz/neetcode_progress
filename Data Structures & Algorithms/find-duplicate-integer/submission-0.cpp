class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ptr = 0;
        while(true)
        {
            int nxt = nums[ptr];
            if(nxt == -1) return ptr;
            nums[ptr] = -1;
            ptr = nxt;
        }
        return -1;
    }
};
