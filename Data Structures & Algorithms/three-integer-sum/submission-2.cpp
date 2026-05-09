class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;

        // greedy two-sum with sorted inputs
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int left=0; left < nums.size() -2; ++ left)
        {
            int mid = left +1, right = n-1;
            // skip dup start
            if(left != 0 && (nums[left] == nums[left -1])) continue;
            while(mid < right)
            {
                int sum = nums[left] + nums[mid] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[left], nums[mid], nums[right]}); mid++; right--;
                                    while(nums[mid] == nums[mid-1]) mid++;    
                                                        while(nums[right] == nums[right+1]) right--;
                }
                else if(sum < 0){ 
                    mid++;
                    
                    while(nums[mid] == nums[mid-1]) mid++;
                }
                else{
                    right--;
                    // need to avoid index that produce duplicate trips
                    while(nums[right] == nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};
