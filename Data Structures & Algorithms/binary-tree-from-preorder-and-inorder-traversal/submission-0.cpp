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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp; // node -> index
        for(int i{}; i < inorder.size(); ++i) mp[inorder[i]] = i;

        int n = inorder.size();
      

        int prev = 0;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode*{
            if(l > r) return nullptr;
            int root_val = preorder[prev++];
            TreeNode* node = new TreeNode(root_val);
            int mid = mp[root_val];
            node -> left = dfs(l, mid-1);
            node -> right = dfs(mid +1, r);
            return node;
        };

        return dfs(0, n-1);

    }
};
