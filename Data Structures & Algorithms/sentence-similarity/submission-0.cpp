class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        if(sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> mp;
        for(const auto &p : similarPairs)
        {
            mp[p[0]].insert(p[1]);
            mp[p[1]].insert(p[0]);
        }

        for(int i{}; i < sentence1.size(); ++i)
        {
            string s = sentence1[i];
            string x = sentence2[i];
            if((!mp.count(s) || !mp[s].count(x)) && s != x) return false;
        }
        return true;
    }
};
