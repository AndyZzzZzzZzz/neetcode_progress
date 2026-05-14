class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;

        int l = 0, _max = 0;
        deque<int> dq;

        for(int r=0; r <nums.size(); ++r)
        {
            while(!dq.empty() && nums[r] > dq.back()) dq.pop_back();

            dq.push_back(nums[r]);

            if(r-l+1 == k)
            {
                ans.push_back(dq.front());
                if(nums[l++] == dq.front())
                {
                    dq.pop_front();
                }
            }

        }
        return ans;
    }
};
