class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int ptr = 0;
        for(int i{}; i < t.size(); ++i)
        {
            if(ptr < s.size() && t[i] == s[ptr]) ptr++;
        }
        return ptr == s.size();
    }
};