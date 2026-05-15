class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // use stack to precompute the shorter bar on left
        // and shorter bar on right
        int n = heights.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);
        int ans = 0;

        vector<int> stk;

        for(int i{}; i < n; ++i)
        {
 
                while(!stk.empty() && heights[i] < heights[stk.back()])
                {
                    right[stk.back()] = i;
                    stk.pop_back();
                }
              stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1; i >= 0; --i)
        {
                while(!stk.empty() && heights[i] < heights[stk.back()])
                {
                    left[stk.back()] = i;
                    stk.pop_back();
                }
             stk.push_back(i);
        }

        for(int i{}; i < n; ++i)
        {
            int h = heights[i];

            int base = right[i] - left[i] - 1;
            ans = max(ans, base * h);
        }
        return ans;
    }
};
