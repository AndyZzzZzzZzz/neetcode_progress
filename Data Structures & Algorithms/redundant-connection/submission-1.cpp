class UnionFind {
    private:
        vector<int> parents;
    public:
        UnionFind(int n){
            parents.resize(n+1, 0);
            iota(parents.begin(), parents.end(), 0);
        }
        bool unite(int v, int u) {
            int pv = find(v);
            int pu = find(u);
            if(pv == pu) return false;
            parents[pv] = pu;
            return true;
        }

        int find(int v) {
            if(parents[v] == v) return v;
            int root = parents[v];
            if(root != parents[root]) return parents[v] = find(root);
            return root;
        }
};



class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind u(edges.size());

        for(auto& e : edges) {
            if(!u.unite(e[0], e[1])) return e;
        }
        return {};
    }
};
