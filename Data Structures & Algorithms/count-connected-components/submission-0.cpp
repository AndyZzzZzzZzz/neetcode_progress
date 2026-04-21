class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        // dfs
        vector<vector<int>> g(n);

        for(const auto& e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> seen(n, false); 
        function<void(int)> dfs = [&](int node)
        {
            if(seen[node]) return;
            seen[node] = true;
            for(int nei : g[node]) if(!seen[nei]) dfs(nei);
        };

        int ans = 0;
        for(int i{}; i < n; ++i)
        {
            if(!seen[i]){ ans++; dfs(i); }
        }
        return ans;
    }
};
