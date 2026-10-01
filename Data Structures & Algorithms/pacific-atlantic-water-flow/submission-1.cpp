class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // mark cells that either ends can reach
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
 
        vector<vector<int>> ans;
        ans.reserve(100000);
        int n = heights.size(), m= heights[0].size();
       
        vector<vector<int>> check(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        for(int i{}; i <n; ++i) {q.push({i,0}); check[i][0] = 1;}
        for(int j{}; j < m; ++j) {q.push({0,j}); check[0][j] = 1;}

        // flow water to atlantic
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            for(int p{}; p < 4; ++p) {
                int ni=x[p]+i, nj = y[p]+j;
                if(ni>=0 && nj >= 0 &&ni < n && nj < m && check[ni][nj] != 1 && heights[i][j] <= heights[ni][nj]) {
                    check[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }

        // flow water to pacific
        for(int i{}; i < n; ++i) {
            q.push({i,m-1}); 
            if(check[i][m-1] == 1) ans.push_back({i, m-1});
            check[i][m-1] = 2;
            }
        for(int j{}; j < m; ++j) {
            q.push({n-1,j}); 
            if(check[n-1][j] == 1) ans.push_back({n-1, j});
            check[n-1][j] = 2;
        }

        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            for(int p{0}; p < 4; ++p) {
                int ni=x[p]+i, nj = y[p]+j;
                if(ni >=0 && nj >= 0 && ni < n && nj < m && check[ni][nj] != 2 && heights[i][j] <= heights[ni][nj]) {
                    if(check[ni][nj] == 1) ans.push_back({ni, nj});
                    check[ni][nj] = 2;
                    q.push({ni, nj});
                }
            }
        }
        return ans;

    }
};
