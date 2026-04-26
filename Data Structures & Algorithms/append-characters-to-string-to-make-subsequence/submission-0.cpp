class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr = 0;
        for(int i{}; i < s.size(); i++) if(ptr < t.size() && s[i]==t[ptr]) ptr++;
        return t.size() - ptr;
    }
};