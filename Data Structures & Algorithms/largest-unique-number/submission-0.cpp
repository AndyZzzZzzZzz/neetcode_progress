class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int _max = -1;
        for(int i : nums) mp[i]++;
        for(const auto &p : mp) if(p.second ==1) _max = max(_max, p.first);
        return _max;
    }
};
