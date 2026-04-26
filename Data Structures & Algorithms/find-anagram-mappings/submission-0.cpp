class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        for(int i{}; i < nums2.size(); ++i) mp[nums2[i]] = i;
        vector<int> ans;

        for(int i{}; i < nums1.size(); ++i) ans.push_back(mp[nums1[i]]);
        return ans;
    }
};
