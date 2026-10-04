class Solution {
public:
    vector<int> partitionLabels(string s) {
        // need to group all elements together
        // track current active characters we are considering
        unordered_map<char, int> mp;
        unordered_set<char> track;
        vector<int> ans;

        for(char c: s) mp[c]++;

        int l = 0;
        for(int r{}; r < s.size(); r++) {
            char c = s[r];
            track.insert(c);
            // finished process this character
            if(--mp[c] == 0){
                mp.erase(c);
                track.erase(c);
            }
            if(track.empty()) {
                ans.push_back(r - l +1);
                l = r +1;
            }
        }
        return ans;
    }
};
