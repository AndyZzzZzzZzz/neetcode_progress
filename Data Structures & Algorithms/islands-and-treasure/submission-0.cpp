class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        const int limit = numeric_limits<int>::max();
        // multi-source bfs on treasure
        queue<vector<int>> q;
        for(int i{}; i < n; ++i) {
            for(int j{}; j < m; ++j) {
                if(grid[i][j] == 0) q.push({i,j, 0});
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()) {
            auto v = q.front(); q.pop();
            int i = v[0], j = v[1], dis = v[2];
            for(int d{}; d < 4; ++d) {
                int ni = dx[d]+i, nj = dy[d]+j;
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && dis+1 <grid[ni][nj]) {
                    grid[ni][nj] = min(grid[ni][nj], dis+1);
                    q.push({ni, nj, grid[ni][nj]});
                }
            }
        }
    
    }
};
