class Solution {
public:
    string minWindow(string s, string t) {
        
        // counter
        unordered_map<char, int> count;
        for(char c : t) count[c]++;

        // track the total matches
        int targ = count.size(), matches = 0;
        // track the minimal length
        int ans = s.size()+1, start{};

        int l{};
        for(int r{}; r < s.size(); ++r) {

            char c = s[r];
            if(count.find(c) == count.end()) continue;

            count[c]--;
            if(count[c] == 0) matches++;
            while(matches == targ) {
                if(r - l + 1 < ans) {
                    ans = r - l + 1;
                    start=l;
                }
                if(count.find(s[l]) != count.end()) {
                    count[s[l]]++;
                    if(count[s[l]] > 0) matches--;
                }
                 l++;
            }
        }

        return (ans==s.size()+1) ? "" : s.substr(start, ans);
    }
};
