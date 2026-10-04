class Solution {
public:
    bool checkValidString(string s) {
        // min max window tracking

        int min_open{}, max_open{}, close{};
        for(char c : s) {
            if(c == '('){min_open++; max_open++;}
            else if(c == ')'){close++;if(close > max_open) return false;}
            else max_open++;
        }
        min_open = 0; max_open = 0; close = 0;
        for(int i = s.size() -1; i >= 0; i--) {
            char c = s[i];
            if(c == ')'){min_open++;max_open++;}
            else if(c == '(') {close++;if(close > max_open) return false;}
            else max_open++;
        }
        return true;
    }
};
