class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stack processing
        vector<int> stk;

        for(const string& t : tokens)
        {
            if(isdigit(t[0]) || (t.size() > 1 && isdigit(t[1])))
            {
                int num = stoi(t);
                stk.push_back(num);
            }else
            {
                int a = stk.back(); stk.pop_back();
                int b = stk.back(); stk.pop_back();

                if(t == "+")
                {
                    stk.push_back(a + b);
                }
                else if(t == "*")
                {
                    stk.push_back(a * b);
                }
                else if(t == "-")
                {
                    stk.push_back(b - a);
                }
                else
                {
                    stk.push_back(b / a);
                }
            }
        }
        return stk.back();
    }
};
