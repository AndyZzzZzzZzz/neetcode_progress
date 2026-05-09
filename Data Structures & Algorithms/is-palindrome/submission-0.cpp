class Solution {
public:
    bool isPalindrome(string s) {
        
        // two pointer technique with C++ char casting in the middle
        int l = 0, r = s.size() -1;

        while(l < r)
        {
            while(l < r && !isalnum(s[l])) ++l;
            while(r > l && !isalnum(s[r])) r--;

          
            if(isalpha(s[l]) && isalpha(s[r])){
                if(tolower(s[l]) != tolower(s[r])) return false;
            }
            else if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};
