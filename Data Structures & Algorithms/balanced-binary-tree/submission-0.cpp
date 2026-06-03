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
    int recur(TreeNode* root, bool& flag)
    {
        if(!root) return 0;

        int l = recur(root -> left, flag);
        int r = recur(root -> right, flag);
        if(abs(l-r) > 1) flag = false;
        return max(l, r)+1;
    }
    bool isBalanced(TreeNode* root) {
        // we need to known the height for left subtree and right subtree
        bool ans = true;
        recur(root, ans);
        return ans;
    }
};
