class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // topological sorting
        vector<int> degree(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        queue<int> q;
        // start on all nodes without dependencies
        for(int i{}; i < numCourses; ++i) if(degree[i]==0) q.push(i);

        int finish = 0;
        while(!q.empty())
        {
            finish++; 
            int curr = q.front(); q.pop();
            
            for(int neighbor : adj[curr])
            {
                if(--degree[neighbor] == 0) q.push(neighbor);
            }
        }
        return finish == numCourses;
    }
};
