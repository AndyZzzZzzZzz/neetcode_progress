class Solution {
public:
    int calculateTime(string keyboard, string word) {
        // convert keyboard
        unordered_map<int, int> mp;
        for(int i{}; i < keyboard.size(); ++i) mp[keyboard[i]]=i;
        int ans = 0;
        for(int i{1}; i < word.size(); ++i) ans += abs(mp[word[i]]- mp[word[i-1]]);
        return ans + mp[word[0]];

    }
};
