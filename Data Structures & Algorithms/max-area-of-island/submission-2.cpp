class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // bfs approach
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        int ans{};

        function<void()> bfs = [&]() {
            int size{};
            
            while(!q.empty()){
                auto [i, j] = q.front(); q.pop();
                size++;
                
                for(int k{}; k < 4; ++k) {
                    int di = x[k]+i, dj = y[k]+j;
                    if(di >= 0 && dj >= 0 && di < n && dj < m && grid[di][dj] == 1) { grid[di][dj] =-1; q.push({di, dj});}
                }
            }
            ans = max(ans, size);
        };

        for(int i{}; i < n; ++i) {
            for(int j{}; j < m; ++j) {
                if(grid[i][j] == 1) {
                   grid[i][j] =-1;
                    q.push({i, j});
                    bfs();
                }
            }
        }
        return ans;



    }
};
