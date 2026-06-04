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
    int kthSmallest(TreeNode* root, int k) {
        // maintain a counter that decrements as we traverse across the tree
        // post order dfs

        int ans = -1;
        function<void(TreeNode*)> dfs = [&](TreeNode* n){

            if(!n || ans != -1) return;

            dfs(n -> left);

            k--;
            if(k == 0) ans = n->val;
            else if(k < 0) return;

            dfs(n -> right);
        
        };

        dfs(root); return ans;   
    }
};
