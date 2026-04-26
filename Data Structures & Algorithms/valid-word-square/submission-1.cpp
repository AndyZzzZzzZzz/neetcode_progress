class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        int n = words.size();
        int prev = INT_MAX;

        for(int i{}; i < n; ++i)
        {
            int m = words[i].size();
            if(m > prev) return false;
            for(int j{}; j < m; ++j)
            {
                if(j >= words.size()) return false;
                if(words[i][j] != words[j][i]) return false;
            }
            prev = m;
        }
        return true;
    }
};
