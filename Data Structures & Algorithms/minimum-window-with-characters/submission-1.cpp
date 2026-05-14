class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> mp;
        for(const char& c : t) mp[c]++;

        int ans = INT_MAX, l=0, minl=0;
        int count = t.size();

        for(int r{}; r < s.size(); ++r)
        {
            if(mp[s[r]] > 0)
            {
                count--;
            }

            mp[s[r]]--;

            while(count == 0)
            {
                if(r-l+1 < ans)
                {
                    ans = r-l+1;
                    minl = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) count++;
                l++;
            }
        }

        return (ans == INT_MAX) ? "" : s.substr(minl, ans);
    }
};
