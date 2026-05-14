class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;

        for(int i{}; i < s.size(); ++i)
        {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stk.empty()) return false;
                if(s[i] == ')' && stk.top() != '(') return false;
                if(s[i] == '}' && stk.top() != '{') return false;
                if(s[i] == ']' && stk.top() != '[') return false;
                stk.pop();
            }else
            {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
