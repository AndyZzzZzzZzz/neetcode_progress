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
    int maxPathSum(TreeNode* root) {
        
        int ans = numeric_limits<int>::min();
        // at each recursion step, max can be left, right, or left + right 
        function<int(TreeNode*)> rec = [&](TreeNode* node) {
            if(node == nullptr) return 0;

            int l = rec(node -> left) + node -> val;
            int r = rec(node -> right) + node -> val;
            int all = l + r - node -> val;
            ans = max({l, r, all, node->val,ans});
            return max({l, r, node->val});

        };
        rec(root);
        return ans;
    }
};
