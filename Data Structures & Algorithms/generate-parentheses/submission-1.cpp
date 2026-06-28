class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        int left = n, right = n;

        vector<string> ans;
        string curr;

        function<void(int, int)> backtrack = [&](int l, int r) {
            if(l == 0 && r == 0) {
                ans.push_back(curr);
                return;
            }
            
            if(l != 0) {
                curr.push_back('(');
                backtrack(l-1, r);
                curr.pop_back();
            }
            if(r > l) {
                curr.push_back(')');
                backtrack(l, r-1);
                curr.pop_back();
            }
        };
        backtrack(n,n); return ans;
    }
};
