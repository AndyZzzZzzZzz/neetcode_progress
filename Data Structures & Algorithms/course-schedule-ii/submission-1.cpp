class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses, 0);

        // [0,1] means 1 unlocks 0
        for(const auto& v : prerequisites) {
            g[v[1]].push_back(v[0]);
            in_degree[v[0]]++;
        }

        // topological sort 
        queue<int> q;
        vector<int> ans;
        for(int i{}; i < numCourses; ++i) if(in_degree[i] == 0) q.push(i);

        while(!q.empty()) {
            
            auto curr = q.front(); q.pop();
            ans.push_back(curr);
            for(int nei : g[curr]) {
                in_degree[nei]--;
                if(in_degree[nei] == 0) q.push(nei);
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>{};
        
    }
};
