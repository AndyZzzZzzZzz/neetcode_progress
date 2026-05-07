class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> cols(10, vector<bool>(10,false));
        vector<vector<bool>> rows(10, vector<bool>(10,false));
        vector<vector<bool>> square(10, vector<bool>(10, false));

        for(int i{}; i < 9; ++i)
        {
            for(int j{}; j < 9; ++j)
            {
                if(!isdigit(board[i][j])) continue;
                int k = board[i][j] - '0';

                if(cols[j][k]) return false;
                if(rows[i][k]) return false;
                if(square[(i/3)*3 + j/3][k]) return false;

                cols[j][k] = true;
                rows[i][k] = true;
                square[(i/3)*3 + (j/3)][k] = true;
            }
        }
        return true;
    }
};
