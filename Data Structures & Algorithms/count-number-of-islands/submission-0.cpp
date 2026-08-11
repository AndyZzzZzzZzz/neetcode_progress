class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        function<void(int,int)> dfs = [&](int i, int j ) {
            
            grid[i][j] = '2';
            for(int d{}; d < 4; ++d) {
                int ni = i + dir[d][0], nj = j + dir[d][1];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1') dfs(ni, nj);
            }
        };

        for(int i{}; i < n; ++i) {
            for(int j{}; j < m; ++j) {
                if(grid[i][j] == '1'){ dfs(i, j); ans++;}
            }
        }
        return ans;
    }
};
