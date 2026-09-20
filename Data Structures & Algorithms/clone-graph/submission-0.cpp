/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        // use map to clone the graph
        unordered_map<Node*, Node*> mp;

        function<Node*(Node*)> dfs = [&](Node* curr) -> Node*{
            if(curr == nullptr) return nullptr;
            if(mp.count(curr)) return mp[curr];
            
            mp[curr] = new Node(curr -> val);
            for(auto n : curr -> neighbors) {
                mp[curr] -> neighbors.push_back(dfs(n));
            }
            return mp[curr];
        };

        return dfs(node);

    }
};
