class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // attempt to track numbers in a set
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;
        // only search from the beginning of a sequence
        for(int i : st)
        {
            if(st.find(i-1) != st.end()) continue;

            int x = i+1;
            int curr = 1;
            while(st.count(x))
            {
                curr++; x++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
