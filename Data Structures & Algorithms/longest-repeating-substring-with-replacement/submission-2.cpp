class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // hash map keeping track of the frequency of all possible characters
        // keep a target character each time and attemped to use it to compute answer
        unordered_map<char, int> mp;
        
        int _max=0, total = 0, l = 0, ans = 0;
        for(int r=0; r < s.size(); ++r)
        {
            mp[s[r]]++;

            _max = max(_max, mp[s[r]]);
            
            while(((r-l+1) - _max) > k)
            {
                mp[s[l]]--; 
                
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
