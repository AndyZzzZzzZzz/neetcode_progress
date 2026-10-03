class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int n = board.size(), m = board[0].size();
        function<void(int, int)> dfs = [&](int x, int y) {
            
            

            board[x][y] = 'C';
            bool check = true;
            for(int i{}; i < 4; ++i) {
                int nx = dx[i] + x, ny = dy[i] + y;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'O') dfs(nx,ny);
            }
        };

        for(int i{}; i < n; ++i) if(board[i][0] == 'O') dfs(i,0);
        for(int i{}; i < n; ++i) if(board[i][m-1] == 'O') dfs(i,m-1);
        for(int i{}; i < m; ++i) if(board[0][i] == 'O') dfs(0,i);
        for(int i{}; i < m; ++i) if(board[n-1][i] == 'O') dfs(n-1,i);

        for(int i{}; i < n; ++i){
            for(int j{}; j < m; ++j) {
                if(board[i][j] == 'C') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};
