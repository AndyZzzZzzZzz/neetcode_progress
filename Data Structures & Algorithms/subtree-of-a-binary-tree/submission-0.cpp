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
    bool same(TreeNode* root, TreeNode* sub)
    {
        if(!root && !sub) return true;
        if(!root || !sub) return false;

        if(root -> val != sub -> val) return false;
        return same(root -> left, sub -> left) && same(root -> right, sub -> right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        return same(root, subRoot) || isSubtree(root -> right, subRoot) || isSubtree(root -> left, subRoot);
    }
};
