class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        // backtacking try to place NQueens on the board
        vector<vector<string>> ans;
        
        // track used columns
        vector<bool> cols(n, false);
        // track used diagnals
        vector<bool> pos_diag(2*n, false);
        vector<bool> neg_diag(2*n, false);

        function<void(vector<string>&, int)> backtrack = [&](vector<string>& board, int r)
        {
            if(r == n) {ans.push_back(board); return;}
            for(int c{}; c < n; ++c) {
                if(!cols[c] && !pos_diag[r+c] && !neg_diag[r-c + n-1]) {
                    cols[c] = true;
                    pos_diag[r+c] = true;
                    neg_diag[r-c+n-1] = true;

                    board[r][c] = 'Q';
                    backtrack(board, r+1);
                    board[r][c] = '.';

                    cols[c] = false;
                    pos_diag[r+c] = false;
                    neg_diag[r-c+n-1] = false;
                }
            }
        };
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return ans;
    }
};
