class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // using dijkstra algo
        // explore distance only if this is better solution
        vector<int> dist(n+1, numeric_limits<int>::max());

        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        // build adj lists
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        while(!q.empty()) {
            auto [d, node] = q.top(); q.pop();

            for(auto nei : adj[node]) {
            
                if(d + nei.second < dist[nei.first]) {
                    dist[nei.first] = d + nei.second;
                    q.push({d + nei.second, nei.first});
                } 
            }
        }

        int res = 0;
        for(int i{1}; i <= n; ++i){

            if(dist[i] == numeric_limits<int>::max()) return -1;
            res = max(res, dist[i]);
        }
        return res;



    }
};
