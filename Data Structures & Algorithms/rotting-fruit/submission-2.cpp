class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0; // total fresh fruits
        int n = grid.size(), m = grid[0].size();
        // bfs on rotten fruit
        queue<pair<int, int>> q;
        for(int i{}; i < n; ++i) {
            for(int j{}; j <m; ++j) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) count++;
            }
        }
        if(count == 0) return 0;
        if(q.size() == 0) return -1;
        
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        
        int size = q.size();
        int minute = 0;
        while(!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            
            if(size == 0) {size = q.size(); minute++; }
            else size--;
            
            for(int p{}; p < 4; ++p) {
                int nx = x[p] + i, ny = y[p] +j;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    count --;
                }
            }
        }
        return (count == 0) ? minute : -1;

    }
};
