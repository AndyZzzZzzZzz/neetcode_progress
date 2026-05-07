class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;
        
        for(const string & s : strs)
        {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }
        for(const auto & p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
