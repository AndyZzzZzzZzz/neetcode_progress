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
    bool isValidBST(TreeNode* root) {
        
        // track minimum value and maximum value for each subtree
        function<bool(int, int, TreeNode*)> dfs = [&](int _min, int _max, TreeNode* n)
        {
            if(!n) return true;

            int v = n -> val;
            if(v >= _max || v <= _min) return false;

            bool left = dfs(_min, v, n -> left);
            bool right = dfs(v, _max, n-> right);
            return left && right;

        };

        return dfs(INT_MIN, INT_MAX, root);
    }
};
