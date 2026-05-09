class Solution {
public:
    int trap(vector<int>& height) {
        
        // go with the monotonic stack approach
        vector<int> stk;
        int ans = 0;
        for(int i{}; i < height.size(); ++i)
        {
            // stack only keeps decreasing bars
            if(stk.empty() || height[i] <= height[stk.back()]){
                stk.push_back(i);
            }
            else{

        
                while(stk.size() > 0 && (height[i] > height[stk.back()]))
                {
                    int idx = stk.back(); stk.pop_back();
                    if(stk.size() == 0) break;
                    int bot = height[idx];
                    ans += (min(height[stk.back()], height[i]) -bot) * (i - stk.back() -1);
                }
                stk.push_back(i);

            }
        }
        return ans;
        
    }
};
