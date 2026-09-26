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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // dfs -> use # to represent nullptr
        // pre order
        string ans = "";
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if(node == nullptr) {
                ans += '#'; 
                ans += ',';
                return;
            }
       

            ans += to_string(node->val);
            ans += ',';
            dfs(node -> left);
            dfs(node -> right);
        };
        dfs(root);
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        
        return buildTree(ss);
    }

    TreeNode* buildTree(stringstream& ss) {
        string token;
        if(!getline(ss, token, ',')) return nullptr;

        if(token == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node -> left = buildTree(ss);
        node -> right = buildTree(ss);
        return node;
    }
};
