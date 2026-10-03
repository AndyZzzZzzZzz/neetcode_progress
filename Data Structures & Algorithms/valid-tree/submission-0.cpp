class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // transform into adj lists
        vector<vector<int>> adj(n);
        for(auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        // cycle detection
        vector<bool> check(n, false);

        function<bool(int, int)> dfs = [&](int curr, int prev) {
            if(check[curr]) return false;
            check[curr] = true;

            for(int nei : adj[curr]) {
                if(nei != prev && !dfs(nei, curr)) return false;
            }
            return true;
        };
        if(!dfs(0, -1)) return false;
        for(bool v : check) if(!v) return false;
        return true;
    }
};
