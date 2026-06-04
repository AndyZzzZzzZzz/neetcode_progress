/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        function<int(TreeNode*, int)> dfs = [&](TreeNode* n, int _max)
        {
            if(!n) return 0;

            int r = dfs(n -> right, max(_max, n -> val));
            int l = dfs(n -> left, max(_max, n -> val));

            if(n -> val >= _max) return r + l + 1;
            return r + l;
        };

        return dfs(root, INT_MIN);
        
    }
};
