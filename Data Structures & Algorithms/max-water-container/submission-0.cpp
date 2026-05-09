class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // straightforward two pointer greedy
        int l = 0, r = heights.size()-1, ans = 0;

        while(l < r)
        {
            int curr = min(heights[l], heights[r]) * (r-l);
            ans = max(ans, curr);
            if(heights[l] < heights[r]) ++ l;
            else --r;
        }
        return ans;
    }
};
