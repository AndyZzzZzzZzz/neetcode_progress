class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int dir[4][2] = {{1,0}, {0,1 }, {-1, 0}, {0, -1}};

        vector<vector<int>> seen(n, vector<int>(m, 0));
        // classic dfs search
        function<bool(int,int,int)> dfs = [&](int pos, int i, int j) {
            if(pos == word.size()) return true;

            seen[i][j] = 1;
            for(auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && board[ni][nj] == word[pos] && !seen[ni][nj]) {
                    if(dfs(pos +1, ni, nj)) return true;
                }
            }
            seen[i][j] = 0;
            return false;
        };

        for(int i{}; i < n; ++i) {
            for(int j{}; j < m; ++j) {
                if(board[i][j] == word[0] && dfs(1, i ,j )) return true; 
            }
        }
        return false;
    }
};
