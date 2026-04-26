class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int ans = 0;
        int ptr = s.size() -1;
        while(ptr >= 0 && !isalpha(s[ptr])) ptr--;
        while(ptr >= 0 && isalpha(s[ptr])){ ptr--;++ans; }
        return ans;
    }
};