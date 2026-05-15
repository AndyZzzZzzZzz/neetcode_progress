class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // monotonic stack problem
        vector<int> stk;
        
        int n = temperatures.size();

        vector<int> ans(n, 0);

        for(int i{}; i < n; ++i)
        {
            if(stk.empty() || temperatures[i] <= temperatures[stk.back()])
            {
                stk.push_back(i);
            }
            else
            {
                // compute result
                while(!stk.empty() && temperatures[i] > temperatures[stk.back()])
                {
                    ans[stk.back()] = i - stk.back();
                    stk.pop_back();
                }
                stk.push_back(i);
            }
        }
        return ans;
    }
};
