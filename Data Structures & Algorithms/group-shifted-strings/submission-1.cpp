class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        
        for (string& s : strings) {
            string key = "";
            for (int i = 1; i < s.size(); ++i) {
                // Calculate distance between adjacent characters
                int diff = (s[i] - s[i-1] + 26) % 26;
                key += to_string(diff) + ","; // Use a separator like ','
            }
            // Strings of length 1 will have an empty key "", which is fine!
            groups[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : groups) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
