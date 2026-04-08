class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // store remainder targets in the array
        unordered_set<int> mp;

        for(int i : nums)
        {
            if(mp.count(i)) return true;
            mp.insert(i);
        }
        return false;
    }
};