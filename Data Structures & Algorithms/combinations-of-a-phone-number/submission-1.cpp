class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // backtracking with predefined mapping
        unordered_map<int, string> mp = {{2,"abc"}, {3, "def"}, {4,"ghi"}, {5,"jkl"}, 
                                        {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
        // use vector for more cache friendly solution.
        vector<string> ans;

        if(digits.size() == 0) return ans;
        function<void(int, string&)> dfs = [&](int pos, string& curr) {
            if(pos >= digits.size()) {
                ans.push_back(curr);
                return;
            }
            int i = digits[pos] - '0';
            for(char& c : mp[i]) {
                curr += c;

                dfs(pos+1, curr);

                curr.pop_back();
            }
        };

        string curr = "";
        dfs(0, curr);
        return ans;
    }
};
