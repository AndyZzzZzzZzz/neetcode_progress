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
    int res = 0;
    int recur(TreeNode* root)
    {
        if(!root) return 0;
   
        int l = recur(root -> left);
        int r = recur(root -> right);

        res = max({res, l+r});
        return max(l,r)+1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        recur(root); return res;
    }
};
